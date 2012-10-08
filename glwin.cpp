#include "glwin.h"

GLWin::GLWin(QWidget *parent)
    : QGLWidget(parent)
{
    resize(400,300);
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
    paintMdl();
}

void GLWin::paintMdl()
{
    vertex v1 = cube.GetVertices().at(0);
    vertex v2 = cube.GetVertices().at(1);
    vertex v3 = cube.GetVertices().at(2);
    qDebug("-------");
    qDebug(QString::number(v1.x).toLocal8Bit());
    qDebug(QString::number(v1.y).toLocal8Bit());
    qDebug(QString::number(v1.z).toLocal8Bit());
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);     // set vertex color to red
    glVertex3f(v1.x,v1.y,v1.z);
    glVertex3f(v2.x,v2.y,v2.z);
    glVertex3f(v3.x,v3.y,v3.z);
    glEnd();
}

