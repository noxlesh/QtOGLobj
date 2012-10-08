#include "modelobj.h"

ModelObj::ModelObj()
{
    objFile.setFileName("cube.obj");
}

void ModelObj::LoadMdl()
{
    if(!objFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //Error loading file
        qDebug("Loading obj model failed");
        return;
    }
    while(!objFile.atEnd()) {
        QByteArray line = objFile.readLine();
        switch(line.at(0))
        {
        case '#':
            //qDebug("Line ignored:found comment");
            break;
        case 'v':
            ParceV(line);
            break;
        }
    }
}

vtxArray ModelObj::GetVertices()
{
    //Check for vtxArr consistency
    if(vtxArr.capacity() == 0) {
        qDebug("Vertex array is empty:");
        if(!objFile.isOpen())
            qDebug("Model file not loaded!");
        else
            qDebug("Something goes wrong!");
    }
    return vtxArr;//All goes right
}

void ModelObj::ParceV(QString line)
{
    vertex tmpVtx;
    int i = 2;//
    QString tmpStr;
    //fox x axis
    while(line.at(i)!=' ') {
        tmpStr.append(line.at(i));
        i++;
    }
    qDebug(tmpStr.toLocal8Bit());
    tmpVtx.x = tmpStr.toFloat();
    tmpStr.clear();
    i++;
    //for y axis
    while(line.at(i)!=' ') {
        tmpStr.append(line.at(i));
        i++;
    }
    qDebug(tmpStr.toLocal8Bit());
    tmpVtx.y = tmpStr.toFloat();
    tmpStr.clear();
    i++;
    //for z axis
    while(line.at(i)!='\n') {
        tmpStr.append(line.at(i));
        i++;
    }
    qDebug(tmpStr.toLocal8Bit());
    tmpVtx.z = tmpStr.toFloat();
    tmpStr.clear();
    //for z axis
    //adding vertex to vertex array
    vtxArr.push_back(tmpVtx);
}

