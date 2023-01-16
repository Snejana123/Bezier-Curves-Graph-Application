#include "derivesample.h"
#include "math.h"

//using namespace std;

derivesample::derivesample(Canvas* canvas)
{
    curCanvas = canvas;
}

void derivesample::addDote(QVector2D newDote){
    dotes.append(newDote);
    curCanvas->addDote(newDote.x(), newDote.y());
    curCanvas->drawCoordinateSystemFigurse();
}



void derivesample::clear(){
    dotes.clear();
    curCanvas->removeAllFigures();
    curCanvas->drawCoordinateSystemFigurse();
}

void derivesample::changeDote(int num, QVector2D dote){
    if (num <= dotes.length()){
        dotes[num-1].setX(dote.x());
        dotes[num-1].setY(dote.y());
        curCanvas->changeDote(num, dote);
        curCanvas->drawCoordinateSystemFigurse();
    }
}


void derivesample::deleteDote(int num){
    if (num <= dotes.length()){
        dotes.removeAt(num-1);
        curCanvas->deleteDote(num);
        curCanvas->drawCoordinateSystemFigurse();
    }
}


void derivesample::setNewCanvas(Canvas* newCanvas){
    delete curCanvas;
    curCanvas = newCanvas;
    for (int i = 0; i < dotes.length(); i++){
        addDote(dotes[i]);
    }
}


QString derivesample::strAnswer(){
   QString ans;
   if (dotes.length() > 0){
        ans = "Current dotes:\n";
        for (int i = 0; i < dotes.length(); i++){
            ans += "Dote " + QString::number(i+1) + ":\n";
            ans += "\tx coorcdinate = " + QString::number(dotes[i].x());
            ans += "\ty coorcdinate = " + QString::number(dotes[i].y()) + "\n";
        }
   }else{
       ans = "Please, enter elements values";
   }
   return ans;
}


int derivesample::getDoteCount(){
    return dotes.length();
}






