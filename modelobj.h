#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <QtCore>
#include <QFile>

class ModelObj
{
public:
    ModelObj();
    void LoadMdl();
private:
    int * vertices;
    QFile objFile;
    std::vector<float(*)[3]> vtxArr;
    void ParceV(QString line);
};

#endif // MODELOBJ_H
