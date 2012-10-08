#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <QtCore>
#include <QFile>
struct vertex{
    float x;
    float y;
    float z;
};

class ModelObj
{
public:
    ModelObj();
    void LoadMdl();
private:
    int * vertices;
    QFile objFile;
    std::vector<vertex> vtxArr;
    void ParceV(QString line);
};

#endif // MODELOBJ_H
