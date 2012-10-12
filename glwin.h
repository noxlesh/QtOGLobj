#ifndef GLWIN_H
#define GLWIN_H

#include <QtGui>
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <vector>
#include  "modelobj.h"

class GLWin : public QGLWidget
{
    Q_OBJECT
    
public:
    GLWin(QWidget *parent = 0);
    ~GLWin();
private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void paintMdl();
    ModelObj cube;
    vtxArray vtxArr;
    QTimer *timer;
    ushort iRot;
};

#endif // GLWIN_H
