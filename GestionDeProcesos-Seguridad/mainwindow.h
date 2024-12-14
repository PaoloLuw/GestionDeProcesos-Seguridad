#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAgregar_clicked();
    void on_btnComenzar_clicked();
    void avanzarTiempo(); // Lógica del temporizador
    void on_btnGenerarAleatorios_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *memoryScene;
    QTimer *timer; // Temporizador

    // Estructura para representar un proceso
    class Proceso {
    public:
        int id;
        int inicio;
        int duracion;
        QColor color;  // Atributo para almacenar el color

        Proceso(int id, int inicio, int duracion)
            : id(id), inicio(inicio), duracion(duracion) {
            // Asignar un color aleatorio al proceso cuando se crea
            color = QColor::fromRgb(QRandomGenerator::global()->generate());
        }
    };

    QList<Proceso> procesos; // Lista de procesos
    QList<Proceso> procesosSimulados;
    int tiempoActual; // Para llevar el tiempo de la simulación

    void actualizarMemoria();
    void agregarProcesoTabla(const Proceso &proceso);
    void simularDesbordamientoControlado();
    void simularDesbordamientoNoControlado();
};

#endif // MAINWINDOW_H
