#include "glwin.h"

GLWin::GLWin(QWidget *parent)
    : QGLWidget(parent)
{
    iRot = 1;
    resize(400,300);
    cube.LoadMdl();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
            timer->start(500);
}
GLWin::~GLWin()
{
}
void GLWin::initializeGL()
{
    qglClearColor(Qt::white);
    glClearDepth( 1.0f );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc( GL_LEQUAL );
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}
void GLWin::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;

    if (nWidth>=nHeight)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void GLWin::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    paintMdl();
}

void GLWin::paintMdl()
{
    glLoadIdentity();
    iRot++;
    glRotatef(iRot,1.0f,0.0f,0.0f);
    for(uint i=0;i<(cube.GetFaces().size());i++) {
        face curFace = cube.GetFaces().at(i);
        vertex v1 = cube.GetVertices().at((curFace.x-1));
        vertex v2 = cube.GetVertices().at((curFace.y-1));
        vertex v3 = cube.GetVertices().at((curFace.z-1));
        glBegin(GL_TRIANGLES);
        glColor3f(1, i/8, 0);     // set vertex color to red
        glVertex3f(v1.x,v1.y,v1.z);
        glVertex3f(v2.x,v2.y,v2.z);
        glVertex3f(v3.x,v3.y,v3.z);
        glEnd();

    }
    timer->start(100);
}

