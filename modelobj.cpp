#include "modelobj.h"

ModelObj::ModelObj()
{
    objFile.setFileName("cube.obj");
}

void ModelObj::LoadMdl()
{
    if(!objFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        //Error loading file
        qDebug("Loading obj model failed");
        return;
    }
    while(!objFile.atEnd()){
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

void ModelObj::ParceV(QString line)
{

    //qDebug("Vertex line found");
    //vertex3d tmpVtx;
    QString tmpStr;
    int sz = line.size();
    for (int i=2;i<(sz-2);i++)
    {
        while((line.at(i)!=' ') && (line.at(i)!='\n')){
            tmpStr.append(line.at(i));
            i++;
        }
        qDebug(tmpStr.toLocal8Bit());
        tmpStr.clear();
    }
}

