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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,2);

}
void GLWin::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    paintMdl();
}

void GLWin::paintMdl()
{

    for(int i=0;i<(cube.GetFaces().size());i++) {
        face curFace = cube.GetFaces().at(i);
        vertex v1 = cube.GetVertices().at((curFace.x-1));
        vertex v2 = cube.GetVertices().at((curFace.y-1));
        vertex v3 = cube.GetVertices().at((curFace.z-1));
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);     // set vertex color to red
        glVertex3f(v1.x,v1.y,v1.z);
        glVertex3f(v2.x,v2.y,v2.z);
        glVertex3f(v3.x,v3.y,v3.z);
        glEnd();
    }
}

