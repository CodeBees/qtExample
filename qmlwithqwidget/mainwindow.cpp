#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*

      If you are using a recent version of Qt, QWidget::createWindoContainer is depricated.
    Create a QQuickWidget instead, and use it a a normal QWidget.


    */

    QQuickWidget *m_quickWidget=new QQuickWidget();
    QUrl source("qrc:/ui/dynamic.qml");

    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView );
    m_quickWidget->setSource(source);

    ui->dynamicQmlEmber->addWidget(m_quickWidget);


    //m_quickWidget->setParent( );

}

MainWindow::~MainWindow()
{
    delete ui;
}
