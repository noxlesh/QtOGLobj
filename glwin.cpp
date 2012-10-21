#include "glwin.h"

GLWin::GLWin(QWidget *parent)
    : QGLWidget(parent)
{
    xTra = 0;
    yTra = 0;
    zTra = 0;
    iRot = 0;
    shadingMode = true;//true is SMOOTH
    fov = 45;// Field of view in degrees
    zN = 5;  //near Z near
    zF = 100;// Z far
    LightAmbient[0] = 1.0f;
    LightAmbient[1] = 1.0f;
    LightAmbient[2] = 1.0f;
    LightAmbient[0] = 1.0f;

    LightDiffuse[0] = 1.0f;
    LightDiffuse[1] = 1.0f;
    LightDiffuse[2] = 1.0f;
    LightDiffuse[3] = 1.0f;

    LightPosition[0] = 0.0f;
    LightPosition[1] = 0.0f;
    LightPosition[2] = 2.0f;
    LightPosition[3] = 1.0f;

    resize(400,300);//window size

    cube = new ModelObj(QString("cube.obj"));
    idx = 0;

    timer = new QTimer(this);
    timer->start(20);//50 fps

    //connectors
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
}
GLWin::~GLWin()
{
    glDeleteLists(idx, 1);
}
void GLWin::initializeGL()
{
    qglClearColor(Qt::black);
    idx = paintMdl();
    //glClearDepth( 1.0f );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc( GL_LEQUAL );
    glEnable (GL_LIGHTING); //enable the lighting
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}
void GLWin::resizeGL(int nWidth, int nHeight)
{
    GLdouble ratio = nWidth/nHeight; //aspect ratio
    GLdouble t = tan((fov*M_PI)/360.0)*zN;
    GLdouble b = -t;
    GLdouble l = ratio*b;
    GLdouble r = -l;
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(l, r, b, t, zN, zF);
    glTranslatef(0.0, 0.0, -20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void GLWin::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(xTra, yTra, zTra);
    glRotatef(iRot, 0.0, 1.0, 0.0);
    glCallList(idx);
}

void GLWin::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key())
    {
    case Qt::Key_S:
        if(shadingMode) {
            glEnable (GL_LIGHTING);
            shadingMode = false;
        }
        else {
            glDisable(GL_LIGHTING);
            shadingMode = true;
        }
        break;
    case Qt::Key_Space:
        iRot=iRot+1;
        break;
    case Qt::Key_Up:
        yTra=yTra-0.2;
        break;
    case Qt::Key_Down:
        yTra=yTra+0.2;
        break;
    case Qt::Key_Left:
        xTra=xTra-0.2;
        break;
    case Qt::Key_Right:
        xTra=xTra+0.2;
        break;
    case Qt::Key_Comma:
        zTra=zTra-0.2;
        break;
    case Qt::Key_Period:
        zTra=zTra+0.2;
        break;
    }
}

GLuint GLWin::paintMdl()
{
    GLuint list;
    list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    qglColor(Qt::red);
    glBegin(GL_TRIANGLES);
    faceArray faces = cube->GetFaces();
    uint facesNum = faces.size();
    vtxArray vetices = cube->GetVertices();

    for(uint i=0;i<facesNum;i++) {
        face curFace = faces.at(i);
        vertex v1 = vetices.at((curFace.x-1));
        vertex v2 = vetices.at((curFace.y-1));
        vertex v3 = vetices.at((curFace.z-1));
        //calculating normal
        glNormal3f(((v2.y-v1.y)*(v3.z-v1.z))-((v3.y-v1.y)*(v2.z-v1.z)), ((v2.x-v1.x)*(v3.z-v1.z))-((v3.x-v1.x)*(v2.z-v1.z)), ((v2.x-v1.x)*(v3.y-v1.y))-((v3.x-v1.x)*(v2.y-v1.y)));
        glVertex3f(v1.x, v1.y, v1.z);
        glVertex3f(v2.x, v2.y, v2.z);
        glVertex3f(v3.x, v3.y, v3.z);
    }

    glEnd();
    glEndList();
    return list;
}

