#include <QtGui/QApplication>
#include "glwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWin w;
    w.show();
    
    return a.exec();
}
