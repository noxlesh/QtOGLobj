#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <QtCore>
#include <QFile>

struct vertex3d{
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
    std::vector<vertex3d> vtxArr;
    void ParceV(QString line);
};

#endif // MODELOBJ_H
