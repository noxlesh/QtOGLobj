#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <QtCore>
#include <QFile>

struct vertex{
    float x;
    float y;
    float z;
};
typedef std::vector<vertex> vtxArray;

class ModelObj
{
public:
    ModelObj();
    void LoadMdl();//Load model file
    vtxArray GetVertices();//Get model vertices
private:
    int * vertices;
    QFile objFile;
    vtxArray vtxArr;
    void ParceV(QString line);
};

#endif // MODELOBJ_H
