#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QDebug> // Para depuración
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), tiempoActual(0) {
    ui->setupUi(this);

    // Crear la escena gráfica
    memoryScene = new QGraphicsScene(this);
    ui->gvMemoria->setScene(memoryScene);


    ui->gvMemoria->setRenderHint(QPainter::Antialiasing);
    ui->gvMemoria->setRenderHint(QPainter::TextAntialiasing);
    ui->gvMemoria->setRenderHint(QPainter::SmoothPixmapTransform);

    ui->gvMemoria->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gvMemoria->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->gvMemoria->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Crear el temporizador
    timer = new QTimer(this);

    ui->tblProcesos->setColumnCount(3);
    ui->tblProcesos->setHorizontalHeaderLabels({"ID", "Inicio", "Duración"});
    ui->tblProcesos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(timer, &QTimer::timeout, this, &MainWindow::avanzarTiempo);
    connect(ui->btnGenerarAleatorios, &QPushButton::clicked, this, &MainWindow::on_btnGenerarAleatorios_clicked);
    connect(ui->btnSimularDesbordamientoControlado, &QPushButton::clicked, this, &MainWindow::simularDesbordamientoControlado);
    connect(ui->btnSimularDesbordamientoNoControlado, &QPushButton::clicked, this, &MainWindow::simularDesbordamientoNoControlado);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnAgregar_clicked() {
    int inicio = ui->sbInicio->value();
    int duracion = ui->sbDuracion->value();

    if (duracion <= 0) {
        ui->statusbar->showMessage("La duración debe ser mayor a 0.", 3000);
        return;
    }

    int id = procesos.size() + 1;

    Proceso nuevoProceso = {id, inicio, duracion}; // Solo usar duración directamente
    procesos.append(nuevoProceso);

    // Agregar a la tabla
    agregarProcesoTabla(nuevoProceso);

    qDebug() << "Proceso agregado: ID=" << id
             << ", Inicio=" << inicio
             << ", Duración=" << duracion;
}
int posicionImpresora = 0;

void MainWindow::on_btnComenzar_clicked() {

    posicionImpresora = 0;

    if (procesos.isEmpty()) {
        ui->statusbar->showMessage("No hay procesos para ejecutar.", 3000);
        return;
    }

    procesosSimulados = procesos;

    tiempoActual = 0;
    memoryScene->clear(); // Limpiar la escena
    timer->start(1000);   // Iniciar el temporizador
    ui->statusbar->showMessage("Simulación iniciada.");
}


int tiempoAnterior = -1;     // Variable para el tiempo del segundo anterior

void MainWindow::avanzarTiempo() {
    ui->tblProcesosSimulados->clearContents();
    ui->tblProcesosSimulados->setRowCount(procesosSimulados.size()); // Ajustar el número de filas

    if (ui->tblProcesosSimulados->columnCount() != 3) {
        ui->tblProcesosSimulados->setColumnCount(3);
        ui->tblProcesosSimulados->setHorizontalHeaderLabels(QStringList() << "ID" << "Inicio" << "Duración");
    }

    bool hayProcesosActivos = false;
    int y = 0;  // Altura inicial para dibujar bloques

    int availableHeight = ui->gvMemoria->height();  // Alto de la vista gráfica

    int blockHeight = availableHeight / procesosSimulados.size();
    blockHeight = qMax(blockHeight, 20);  // Evitar que el bloque sea demasiado pequeño

    qDebug() << "Segundo " << tiempoActual + 1; // Mostrar el segundo actual en consola

    // Mostrar los procesos en consola
    for (const Proceso &proceso : procesosSimulados) {
        qDebug() << "Id" << proceso.id
                 << ", Proceso Inicio:" << proceso.inicio
                 << ", Duración:" << proceso.duracion;
    }

    int row = 0;  // Contador de filas
    for (Proceso &proceso : procesosSimulados) {
        // Guardar duración antes de actualizarla
        int duracionAntes = proceso.duracion;

        if (tiempoActual >= proceso.inicio && proceso.duracion > 0) {
            proceso.duracion--;
        }

        if (duracionAntes != proceso.duracion && tiempoActual >= proceso.inicio) {
            // Pintar el bloque en la posición de la impresora
            QRectF rect(posicionImpresora, y, 40, blockHeight);  // La posición horizontal se mantiene igual
            QGraphicsRectItem *block = memoryScene->addRect(rect);
            block->setBrush(proceso.color);  // Color del bloque actual

            qDebug() << "Dibujando proceso ID=" << proceso.id
                     << " en posición (" << posicionImpresora << "," << y << ")";

        }

        y += blockHeight + 5;  // Ajustar la posición vertical para el siguiente proceso

        // Verificar si el proceso sigue activo
        if (proceso.duracion > 0) {
            hayProcesosActivos = true;
        }

        auto idItem = new QTableWidgetItem(QString::number(proceso.id));
        idItem->setForeground(QBrush(Qt::white));
        idItem->setBackground(QBrush(proceso.color));
        ui->tblProcesosSimulados->setItem(row, 0, idItem);

        auto inicioItem = new QTableWidgetItem(QString::number(proceso.inicio));
        inicioItem->setForeground(QBrush(Qt::white));
        inicioItem->setBackground(QBrush(proceso.color));
        ui->tblProcesosSimulados->setItem(row, 1, inicioItem);

        auto duracionItem = new QTableWidgetItem(QString::number(proceso.duracion));
        duracionItem->setForeground(QBrush(Qt::white));
        duracionItem->setBackground(QBrush(proceso.color));
        ui->tblProcesosSimulados->setItem(row, 2, duracionItem);

        row++;  // Incrementar el contador de filas
    }

    if (tiempoActual != tiempoAnterior) {
        posicionImpresora += 40;
        tiempoAnterior = tiempoActual;
    }

    // Avanzar el tiempo
    tiempoActual++;

    // Detener la simulación si no hay procesos activos
    if (!hayProcesosActivos) {
        timer->stop();
        ui->statusbar->showMessage("Simulación completada.", 3000);
        qDebug() << "Simulación completada.";
    }
}



// PUNTO DE GUARDADO 3 =_= =_= =_=

void MainWindow::on_btnGenerarAleatorios_clicked() {
    int cantidad = (ui->sbCantidad->value())/2; // Obtener la cantidad de procesos a generar

    if (cantidad <= 0) {
        ui->statusbar->showMessage("La cantidad debe ser mayor a 0.", 3000);
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        int inicio = QRandomGenerator::global()->bounded(0, 25); // Inicio aleatorio entre 0 y 99
        int duracion = QRandomGenerator::global()->bounded(1, 25); // Duración aleatoria entre 1 y 20

        int id = procesos.size() + 1;

        // Crear y agregar el proceso
        Proceso nuevoProceso = {id, inicio, duracion};
        procesos.append(nuevoProceso);

        // Agregar a la tabla
        agregarProcesoTabla(nuevoProceso);

        qDebug() << "Proceso aleatorio agregado: ID=" << id
                 << ", Inicio=" << inicio
                 << ", Duración=" << duracion;
    }

    ui->statusbar->showMessage(QString::number(cantidad) + " procesos aleatorios generados.", 3000);
}




void MainWindow::agregarProcesoTabla(const Proceso &proceso) {
    int row = ui->tblProcesos->rowCount();
    ui->tblProcesos->insertRow(row);

    ui->tblProcesos->setItem(row, 0, new QTableWidgetItem(QString::number(proceso.id)));
    ui->tblProcesos->setItem(row, 1, new QTableWidgetItem(QString::number(proceso.inicio)));
    ui->tblProcesos->setItem(row, 2, new QTableWidgetItem(QString::number(proceso.duracion)));
} //


void MainWindow::simularDesbordamientoControlado() {
    // Verificar si hay procesos para simular
    if (procesosSimulados.isEmpty()) {
        QMessageBox::warning(this, "Error", "No hay procesos simulados para aplicar desbordamiento controlado.");
        return;
    }
    int numProcesos = procesosSimulados.size();
    int numProcesosAfectados = qMax(1, numProcesos / 20); // Al menos uno
    const int duracionMaximaPermitida = 10;

    QVector<Proceso> procesosAfectados;

    // Seleccionar y procesar los procesos afectados
    for (int i = 0; i < numProcesosAfectados; ++i) {
        int indice = QRandomGenerator::global()->bounded(procesosSimulados.size());
        Proceso &proceso = procesosSimulados[indice];
        int incremento = QRandomGenerator::global()->bounded(20);
        int nuevaDuracion = proceso.duracion + incremento;

        if (nuevaDuracion > duracionMaximaPermitida) {
            // Si excede, no se realiza el cambio
            QMessageBox::warning(this, "Advertencia",
                                 QString("El proceso ID %1 excedería el límite permitido. Incremento rechazado.")
                                     .arg(proceso.id));
        } else {
            // Si no excede, aplicar el incremento
            proceso.duracion = nuevaDuracion;
            procesosAfectados.append(proceso);
        }
    }
    // Crear mensaje detallado para los procesos afectados
    QString mensaje = "Procesos modificados con éxito bajo desbordamiento controlado:\n";
    for (const Proceso &proceso : procesosAfectados) {
        mensaje += QString("ID: %1 | Nueva duración: %2\n")
                       .arg(proceso.id)
                       .arg(proceso.duracion);
    }

    if (procesosAfectados.isEmpty()) {
        mensaje = "No se modificó ningún proceso porque todos excedían el límite permitido.";
    }

    QMessageBox::information(this, "Resultados del Desbordamiento Controlado", mensaje);

    avanzarTiempo();
}


void MainWindow::simularDesbordamientoNoControlado() {
    QVector<Proceso> procesosAfectados;

    // Determinar el número de procesos afectados (una décima parte del total)
    int numProcesos = procesosSimulados.size();
    int numProcesosAfectados = qMax(1, numProcesos / 20);  // Al menos uno

    for (int i = 0; i < numProcesosAfectados; ++i) {
        int indice = QRandomGenerator::global()->bounded(procesosSimulados.size());
        Proceso &proceso = procesosSimulados[indice];

        int incremento = QRandomGenerator::global()->bounded(20);  // Valor entre 0 y 10
        proceso.duracion += incremento;

        procesosAfectados.append(proceso);
    }

    // Crear mensaje detallado sobre los procesos afectados
    QString mensaje = "El desbordamiento no controlado afectó los siguientes procesos:\n";
    for (const Proceso &proceso : procesosAfectados) {
        mensaje += QString("ID: %1 | Duración incrementada a: %2\n")
                       .arg(proceso.id)
                       .arg(proceso.duracion);
    }

    bool memoriaExtendida = procesosAfectados.size() > 5;  // Ejemplo: si más de 5 procesos fueron afectados
    if (memoriaExtendida) {
        mensaje += "\nNota: La memoria se ha extendido debido al desbordamiento en múltiples procesos.";
    } else {
        mensaje += "\nLa memoria se mantuvo estable a pesar del desbordamiento.";
    }

    QMessageBox::information(this, "Desbordamiento No Controlado", mensaje);

    avanzarTiempo();
}


