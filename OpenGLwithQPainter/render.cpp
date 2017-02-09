#include "render.h"
GLfloat tri[] =
{
    0.0f,1.0f,-1.0f,1.0f,
    1.0f,1.0f,-1.0f,1.0f,
    1.0f,0.0f,-1.0f,1.0f,

};
Render::Render()
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    //format.setVersion(3,3);
    //format.setProfile(QSurfaceFormat::CoreProfile);

    setFormat( format);
    //setFormat(requestedFormat());
    rota = 1.5;
    needInit = true;
    resize(640,480);
    //setAutoFillBackground(false);
    time =  new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(update()));
    time->start(50);
}

void Render::paintEvent(QPaintEvent *e)
{
    makeCurrent();
    paintGL();
    QPainter pter(this);

    QImage pic;
    pic.load(":/timg.jpg");

    pter.setPen(Qt::blue);
    pter.drawText(20,50,"This is a Text!");

    pter.drawEllipse(80,100,40,50);
    pter.drawImage(200,40,pic);

    pter.end();
    update();

}

Render::~Render()
{

}
void Render::initializeGL()
{
    //f = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
    //f->initializeOpenGLFunctions();

    initializeOpenGLFunctions();
    //    f = context()->functions();

}
void Render::resizeGL(int w ,int h)
{

    p.setToIdentity();
    p.perspective(35.0f,float(w)/float(h),1.0f,30.0f);

}

void Render::paintGL()
{   

    QOpenGLShaderProgram  programs ;
    programs.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                     "#version 330 core \n\
                                     layout(location = 0) in vec4 vertex;\
            uniform mat4 mvp;\
    void main() \
    {\
        gl_Position = mvp * vertex;\
    }");

    programs.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                     "#version 330 core \n\
                                     out vec4 fragColor;\
            void main() \
    { \
        fragColor = vec4(0.0f,1.0f,0.0f,1.0f);\
    }");
    programs.link();

    QOpenGLVertexArrayObject vaos;
    vaos.create();
    glBindVertexArray(vaos.objectId());
    QOpenGLBuffer triangles(QOpenGLBuffer::VertexBuffer);
    triangles.create();
    glBindBuffer(GL_ARRAY_BUFFER,triangles.bufferId());
    triangles.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    triangles.allocate(tri,sizeof(tri));
    programs.enableAttributeArray(0);
    programs.setAttributeBuffer(0,GL_FLOAT,0,4,0);

    glEnable(GL_DEPTH_TEST);

    needInit = false;


    glViewport(0,0,width(),height());
    glClearColor(1.0f,0.5f,0.5f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

    programs.bind();
    mv.setToIdentity();

    mv.lookAt(QVector3D(0.0f,0.0f,5.0f),QVector3D(0.0f,0.0f,0.0f),QVector3D(0.0f,1.0f,0.0f));
    mv.rotate(0.5+rota,0,1,0);
    programs.setUniformValue("mvp",p*mv);
    glBindVertexArray(vaos.objectId());
    glDrawArrays(GL_TRIANGLES,0,3);
    rota=rota+1.5;



}
