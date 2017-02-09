#ifndef RENDER_H
#define RENDER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QtWidgets>
#include <QMatrix4x4>
#include <QOpenGLWindow>
#include <QPaintEvent>
#include <QOpenGLPaintDevice>
class Render : public QOpenGLWindow,protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    Render();
    ~Render();
protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int  w ,int h);
    //void exposeEvent(QPaintEvent * e);
    void paintEvent(QPaintEvent * e);

    QOpenGLFunctions_3_3_Core * f;
    QOpenGLBuffer * triangle;
    QOpenGLVertexArrayObject * vao;
    QOpenGLShaderProgram * program;
    QMatrix4x4 mv,p;
    QTimer * time;
    float rota;
    QPainter * painter;
    bool needInit;
    QOpenGLPaintDevice * m_device;
    QPaintEvent * e;
    //void paintEvent(QPaintEvent *e);
public slots:
   // void updateGL();

};

#endif // RENDER_H
