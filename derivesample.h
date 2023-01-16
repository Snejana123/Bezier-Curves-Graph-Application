#ifndef DERIVESAMPLE_H
#define DERIVESAMPLE_H

#include <QAbstractItemModel>
#include "canvas.h"
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QTextEdit>

class derivesample
{

    //Q_OBJECT
public:
    derivesample(Canvas*);
    void setNewCanvas(Canvas*);
    QString strAnswer();
    void addDote(QVector2D);
    void clear();
    void changeDote(int num, QVector2D dote);
    void deleteDote(int num);
    void draw();
    int getDoteCount();
private:
    int flag ;
    QVector<QVector2D> dotes;
    //float circleX;
    //float circleY;
    //float radius;
    Canvas *curCanvas;
    void redrawBezye();
    void calcDraw();

//signals:
   // void sampleError();
};

#endif // DERIVESAMPLE_H
