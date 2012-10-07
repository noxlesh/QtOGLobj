#ifndef GLWIN_H
#define GLWIN_H

#include <QtGui>
#include <QGLWidget>
#include <QtOpenGL>
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
    GLfloat v1[3];
    GLfloat v2[3];
    GLfloat v3[3];
    ModelObj cube;
};

#endif // GLWIN_H
