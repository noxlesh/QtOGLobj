#include "glwin.h"

GLWin::GLWin(QWidget *parent)
    : QGLWidget(parent)
{
    resize(400,300);
    v1[0]= 1;
    v1[1]= 0;
    v1[2]= 0;
    v2[0]= 0;
    v2[1]= 1;
    v2[2]= 0;
    v3[0]= 0;
    v3[1]= 0;
    v3[2]= 0;
    cube.LoadMdl();
}
GLWin::~GLWin()
{
}
void GLWin::initializeGL()
{
    qglClearColor(Qt::white);
}
void GLWin::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int h1 = w*(16/10);
    glViewport(0, 0, (GLint)w, (GLint)h1);
}
void GLWin::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);     // set vertex color to red
    glVertex3fv(v1);        // draw a triangle with v1, v2, v3
    glVertex3fv(v2);
    glVertex3fv(v3);
    glEnd();
}

