#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
{
    // We must call setSurfaceType(QWindow::OpenGLSurface) to tell Qt we prefer to use OpenGL to render the images to screen, instead of QPainter.
    setSurfaceType(QWindow::OpenGLSurface);

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 1); // OpenGL 2.1
    setFormat(format);
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();


}
MainWindow::~MainWindow()
{

}
void MainWindow::initializeGL()
{
    resizeGL(this->width(), this->height());
}

void MainWindow::resizeGL(int w, int h)
{

    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    qreal aspectRatio = qreal(w) / qreal(h);
    glOrtho(-1 * aspectRatio, 1 * aspectRatio, -1, 1, 1, -1);


}


void MainWindow::paintGL()
{

    //The geometric primitive types supported by OpenGL are points, lines, linestrips, line loops,
    //polygons, quads, quad strips, triangles, triangle strips, and triangle fans.

    // Initialize clear color (cornflower blue)
    glClearColor(0.39f, 0.58f, 0.93f, 1.f);
    // Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.8f, -0.8f);
    glColor3f(1.f, 1.f, 0.f); glVertex2f(0.3f, -0.8f);
    glColor3f(0.f, 1.f, 0.f); glVertex2f(0.3f, 0.3f);
    glColor3f(0.f, 0.f, 1.f); glVertex2f(-0.8f, 0.3f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.4f, -0.4f);
    glColor3f(0.f, 1.f, 0.f); glVertex2f(0.8f, -0.1f);
    glColor3f(0.f, 0.f, 1.f); glVertex2f(-0.1f, 0.8f);
    glEnd();
    glFlush();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}
void MainWindow::resizeEvent(QResizeEvent *event)
{

    resizeGL(this->width(), this->height());
    this->update();

}
