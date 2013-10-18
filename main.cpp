#include <QApplication>
#include "glwin.h"

int main(int argc, char *argv[])
{
    #ifdef Q_OS_LINUX
    setlocale(LC_NUMERIC, "C");
    #endif
    QApplication a(argc, argv);
    GLWin w;
    w.show();
    
    return a.exec();
}
