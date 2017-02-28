#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/glu.h>


#include <QOpenGLWindow>
#include <QTimer>


class MainWindow : public QOpenGLWindow
{
  Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
  void updateAnimation();

  protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
  QOpenGLContext* context;
  QOpenGLFunctions* openGLFunctions;
  float rotation;


};


#endif // MAINWINDOW_H


