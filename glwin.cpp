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
    //GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum (-1, 1, -1, 1, 3, 10);
    glTranslatef(0.0, 0.0, -7.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void GLWin::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //iRot++;
    glRotatef(iRot,1.0f,0.0f,0.0f);
    paintMdl();
    timer->start(5);
    glColor3f(1, 0, 0);     // set vertex color to red
}
void GLWin::paintMdl()
{
    faceArray faces = cube.GetFaces();
    uint facesNum = faces.size();
    vtxArray vetices = cube.GetVertices();
    glBegin(GL_TRIANGLES);
    for(uint i=0;i<facesNum;i++) {
        face curFace = cube.GetFaces().at(i);
        vertex v1 = vetices.at((curFace.x-1));
        vertex v2 = vetices.at((curFace.y-1));
        vertex v3 = vetices.at((curFace.z-1));
        glVertex3f(v1.x,v1.y,v1.z);
        glVertex3f(v2.x,v2.y,v2.z);
        glVertex3f(v3.x,v3.y,v3.z);
    }
    glEnd();
}

