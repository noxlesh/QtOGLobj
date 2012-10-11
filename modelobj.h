#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <QtCore>
#include <QFile>

struct vertex {
    float x;
    float y;
    float z;
};
struct face {
    uint x;
    uint y;
    uint z;
};

typedef std::vector<vertex> vtxArray;
typedef std::vector<face> faceArray;

class ModelObj
{
public:
    ModelObj();
    void LoadMdl();//Load model file
    vtxArray GetVertices();//Get model vertices
    faceArray GetFaces();//Get model faces
private:
    int * vertices;
    QFile objFile;
    vtxArray vtxArr;
    faceArray fArr;
    void ParceV(QByteArray line);
    void ParceF(QByteArray line);
};

#endif // MODELOBJ_H
