#include <QApplication>
#include <QSurfaceFormat>
//#include "form.h"
#include "render.h"
int main(int argc,char * argv[])
{
    QApplication a(argc,argv);

    //    QSurfaceFormat format;
    //    format.setVersion(3,3);
    //    format.setProfile(QSurfaceFormat::CoreProfile);
    //    QSurfaceFormat::setDefaultFormat(format);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    // setFormat(format);
    Render r;
    r.show();
    return a.exec();
}
