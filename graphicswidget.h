#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H

#include <QAbstractItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include<QWidget>

#include "canvas.h"
#include "derivesample.h"

class graphicsWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout *mainLayout, *mainVerLayout;
    QHBoxLayout *mainHorLayout, *doteAddLayout, *doteDeleteLayout, *doteChangeLayout;
    QPushButton *addDoteBtn, *deleteDoteBtn, *changeDoteBtn;
    QLabel *doteAddXLabel, *doteAddYLabel, *doteDelLabel, *doteDelXLabel, *doteDelYLabel, *doteChangeNumLabel, *doteChangeXLabel, *doteChangeYLabel;
    QLineEdit *doteAddXEdit, *doteAddYEdit, *doteDelEdit, *doteChangeEdit, *doteChangeXEdit, *doteChangeYEdit;
    QTextEdit* curDotesTEdit;

    Canvas *canvasW;
    derivesample *calcSamp;
    QVector <QVector2D> dotes;
    //QVector3D * theCircle;
    //QVector4D * theLine;
    QString errorMessage;
    bool maybeExport();
    bool saveAs(const QString &);
    bool loadFile(const QString &);

private slots:
    //void addDoteBtnSlot();
    //void deleteDoteBtnSlot();
    void changeDoteSlot();
    void addDoteSlot();
    void deleteDoteSlot();
public:
    graphicsWidget(QWidget *parent = nullptr);
    ~graphicsWidget();
    bool exportSolution();
    bool import();
    bool importFile(QString);


public slots:
    void newSlot();
    void importSlot();
    void ansTextSlot();
};

#endif // GRAPHICSWIDGET_H
