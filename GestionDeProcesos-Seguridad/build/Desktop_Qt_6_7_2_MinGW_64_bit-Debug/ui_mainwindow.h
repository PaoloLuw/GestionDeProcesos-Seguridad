/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *sbInicio;
    QSpinBox *sbDuracion;
    QPushButton *btnAgregar;
    QPushButton *btnSimularDesbordamientoControlado;
    QGraphicsView *gvMemoria;
    QTableWidget *tblProcesos;
    QPushButton *btnComenzar;
    QTableWidget *tblProcesosSimulados;
    QSpinBox *sbCantidad;
    QPushButton *btnGenerarAleatorios;
    QFrame *line;
    QPushButton *btnSimularDesbordamientoNoControlado;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sbInicio = new QSpinBox(centralwidget);
        sbInicio->setObjectName("sbInicio");
        sbInicio->setGeometry(QRect(50, 60, 81, 29));
        sbDuracion = new QSpinBox(centralwidget);
        sbDuracion->setObjectName("sbDuracion");
        sbDuracion->setGeometry(QRect(230, 60, 91, 29));
        btnAgregar = new QPushButton(centralwidget);
        btnAgregar->setObjectName("btnAgregar");
        btnAgregar->setGeometry(QRect(50, 90, 281, 31));
        btnSimularDesbordamientoControlado = new QPushButton(centralwidget);
        btnSimularDesbordamientoControlado->setObjectName("btnSimularDesbordamientoControlado");
        btnSimularDesbordamientoControlado->setGeometry(QRect(60, 570, 251, 29));
        gvMemoria = new QGraphicsView(centralwidget);
        gvMemoria->setObjectName("gvMemoria");
        gvMemoria->setGeometry(QRect(390, 50, 831, 581));
        gvMemoria->setTabletTracking(false);
        gvMemoria->setAutoFillBackground(false);
        tblProcesos = new QTableWidget(centralwidget);
        tblProcesos->setObjectName("tblProcesos");
        tblProcesos->setGeometry(QRect(30, 200, 311, 131));
        btnComenzar = new QPushButton(centralwidget);
        btnComenzar->setObjectName("btnComenzar");
        btnComenzar->setGeometry(QRect(60, 530, 251, 29));
        tblProcesosSimulados = new QTableWidget(centralwidget);
        tblProcesosSimulados->setObjectName("tblProcesosSimulados");
        tblProcesosSimulados->setGeometry(QRect(30, 360, 311, 151));
        sbCantidad = new QSpinBox(centralwidget);
        sbCantidad->setObjectName("sbCantidad");
        sbCantidad->setGeometry(QRect(130, 140, 81, 29));
        btnGenerarAleatorios = new QPushButton(centralwidget);
        btnGenerarAleatorios->setObjectName("btnGenerarAleatorios");
        btnGenerarAleatorios->setGeometry(QRect(230, 140, 101, 29));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(370, 10, 20, 631));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        btnSimularDesbordamientoNoControlado = new QPushButton(centralwidget);
        btnSimularDesbordamientoNoControlado->setObjectName("btnSimularDesbordamientoNoControlado");
        btnSimularDesbordamientoNoControlado->setGeometry(QRect(60, 610, 251, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 340, 151, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 40, 91, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 10, 171, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 180, 151, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 140, 71, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 10, 301, 20));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(390, 30, 831, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(1220, 40, 20, 601));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(30, 170, 311, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(30, 510, 311, 16));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(30, 123, 311, 20));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(30, 30, 311, 16));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(390, 630, 831, 16));
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAgregar->setText(QCoreApplication::translate("MainWindow", "Agregar Manualmente", nullptr));
        btnSimularDesbordamientoControlado->setText(QCoreApplication::translate("MainWindow", "Desbordamiento Controlado", nullptr));
        btnComenzar->setText(QCoreApplication::translate("MainWindow", "Comenzar", nullptr));
        btnGenerarAleatorios->setText(QCoreApplication::translate("MainWindow", "Generar", nullptr));
        btnSimularDesbordamientoNoControlado->setText(QCoreApplication::translate("MainWindow", "Desbordamiento no Controlado", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Inicio:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Orden de ejecuci\303\263n", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "MEMORIA DE PROCESOS", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Datos de los procesos", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Aleatorio:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "SEGURIDAD EN LA GESTION DE PROCESOS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
