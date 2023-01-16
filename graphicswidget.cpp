#include "graphicswidget.h"

#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QMessageBox>
#include <QFileDialog>


graphicsWidget::graphicsWidget(QWidget *parent)
    : QWidget(parent)
{
    //setStyleSheet("background: #CCFFFF;");
    setMinimumSize(650, 700);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //QRegularExpression lineVal("([0][\.][0-9]+) | ([1-9]+[0-9]*[\.][0-9]+) | ([1-9]+[0-9]*)");
    QRegularExpression lineVal("(([-]?[0][\.][0-9]+)|([-]?[1-9]+[0-9]*([\.][0-9]+)?))|([0])");
    QRegularExpression positiveVal("(([0][\.][0-9]+)|([1-9]+[0-9]*([\.][0-9]+)?))|([0])");
    QRegularExpression naturalNum ("[1-9]+[0-9]*");
    QRegularExpressionValidator * natNumVal = new QRegularExpressionValidator(naturalNum);
    QRegularExpressionValidator  * val = new QRegularExpressionValidator(lineVal);
    QRegularExpressionValidator  * positVal = new QRegularExpressionValidator(positiveVal);
    QString lineEdStyle = "QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #EEFBFF; selection-background-color: blue; height: 22px; font-size:18px;}";
    QString labelStyle = "QLabel {font-size: 18px;}";
    QString btnStyle = "QPushButton {background: #FFB256; border-radius: 10px; border: 2px solid gray; height: 25px; width: 100px; font-size: 18px;}";
    QString textEdStyle = "QTextEdit {font-size: 14px; background: #CCFDE1; border-radius: 10px; border: 1px solid gray;}";


    mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(5);
    canvasW = new Canvas(this);
    calcSamp = new derivesample(canvasW);
    canvasW->setStatusTip("Drawing");
    mainLayout->addWidget(canvasW);
    mainHorLayout = new QHBoxLayout;
    mainVerLayout = new QVBoxLayout;


    doteAddLayout = new QHBoxLayout;
    doteAddLayout->setSpacing(5);
    doteAddLayout->setAlignment(Qt::AlignLeft);

    doteAddXLabel  = new QLabel("Dote x coordinete:");
    doteAddXLabel->setStyleSheet(labelStyle);

    doteAddXEdit = new QLineEdit(this);
    doteAddXEdit->setMaximumWidth(200);
    doteAddXEdit->setAlignment(Qt::AlignLeft);
    doteAddXEdit->setValidator(val);
    doteAddXEdit->setStyleSheet(lineEdStyle);
    doteAddXEdit->setStatusTip("Adding dote x coordinate value");

    doteAddLayout->addWidget(doteAddXLabel);
    doteAddLayout->addWidget(doteAddXEdit);

    doteAddYEdit = new QLineEdit(this);
    doteAddYEdit->setMaximumWidth(200);
    doteAddYEdit->setAlignment(Qt::AlignLeft);
    doteAddYEdit->setValidator(val);
    doteAddYEdit->setStyleSheet(lineEdStyle);
    doteAddYEdit->setStatusTip("Adding dote y coordinate value");

    doteAddYLabel = new QLabel("Dote y coordinate:");
    doteAddYLabel->setStyleSheet(labelStyle);

    doteAddLayout->addWidget(doteAddYLabel);
    doteAddLayout->addWidget(doteAddYEdit);

    mainVerLayout->addLayout(doteAddLayout);

    addDoteBtn = new QPushButton("Add point");
    addDoteBtn->setStatusTip("Add point to the defining polyline");
    addDoteBtn->setStyleSheet(btnStyle);

    mainVerLayout->addWidget(addDoteBtn);

    doteDeleteLayout = new QHBoxLayout;
    doteDeleteLayout->setSpacing(5);

    doteDelLabel = new QLabel("Deleting dote number:");
    doteDelLabel->setStyleSheet(labelStyle);


    doteDelEdit = new QLineEdit(this);
    doteDelEdit->setMaximumWidth(200);
    doteDelEdit->setAlignment(Qt::AlignLeft);
    doteDelEdit->setValidator(natNumVal);
    doteDelEdit->setStatusTip("Adding dote y coordinate value");
    doteDelEdit->setStyleSheet(lineEdStyle);

    doteDeleteLayout->addWidget(doteDelLabel);
    doteDeleteLayout->addWidget(doteDelEdit);

    mainVerLayout->addLayout(doteDeleteLayout);

    deleteDoteBtn = new QPushButton("Delete point");
    deleteDoteBtn->setStatusTip("Delete defining polyline point");
    deleteDoteBtn->setStyleSheet(btnStyle);

    mainVerLayout->addWidget(deleteDoteBtn);

    doteChangeLayout =  new QHBoxLayout;
    doteChangeLayout->setSpacing(5);

    doteChangeNumLabel = new QLabel("Changing dote number:");
    doteChangeNumLabel->setStyleSheet(labelStyle);
    doteChangeLayout->addWidget(doteChangeNumLabel);

    doteChangeEdit = new QLineEdit(this);
    doteChangeEdit->setMaximumWidth(200);
    doteChangeEdit->setAlignment(Qt::AlignLeft);
    doteChangeEdit->setValidator(natNumVal);
    doteChangeEdit->setStatusTip("Changing dote number indication:");
    doteChangeEdit->setStyleSheet(lineEdStyle);
    doteChangeLayout->addWidget(doteChangeEdit);

    doteChangeXLabel = new QLabel("Dote x coordinate:");
    doteChangeXLabel->setStyleSheet(labelStyle);
    doteChangeLayout->addWidget(doteChangeXLabel);

    doteChangeXEdit = new QLineEdit(this);
    doteChangeXEdit->setMaximumWidth(200);
    doteChangeXEdit->setAlignment(Qt::AlignLeft);
    doteChangeXEdit->setValidator(val);
    doteChangeXEdit->setStatusTip("Changing dote x coordinate indication:");
    doteChangeXEdit->setStyleSheet(lineEdStyle);
    doteChangeLayout->addWidget(doteChangeXEdit);

    doteChangeYLabel = new QLabel("Dote y coordinate:");
    doteChangeYLabel->setStyleSheet(labelStyle);
    doteChangeLayout->addWidget(doteChangeYLabel);

    doteChangeYEdit = new QLineEdit(this);
    doteChangeYEdit->setMaximumWidth(200);
    doteChangeYEdit->setAlignment(Qt::AlignLeft);
    doteChangeYEdit->setValidator(val);
    doteChangeYEdit->setStatusTip("Changing dote y coordinate indication:");
    doteChangeYEdit->setStyleSheet(lineEdStyle);
    doteChangeLayout->addWidget(doteChangeYEdit);

    mainVerLayout->addLayout(doteChangeLayout);

    changeDoteBtn = new QPushButton("Change dote");
    changeDoteBtn->setStatusTip("Change defining polyline point");
    changeDoteBtn->setStyleSheet(btnStyle);

    mainVerLayout->addWidget(changeDoteBtn);

    curDotesTEdit = new QTextEdit;
    curDotesTEdit ->setMinimumHeight(70);
    curDotesTEdit->setMinimumWidth(300);
    curDotesTEdit->setMaximumWidth(450);
    curDotesTEdit->setReadOnly(true);
    curDotesTEdit->setStyleSheet(textEdStyle);
    curDotesTEdit->setStatusTip("Current dote information.");
    curDotesTEdit->setText("Please, enter points coordinates");

    mainHorLayout->addWidget(curDotesTEdit);
    mainHorLayout->addLayout(mainVerLayout);

    mainLayout->addLayout(mainHorLayout);

    //mainLayout->addWidget(curDotesTEdit);


    setLayout(mainLayout);

    connect(addDoteBtn, SIGNAL(pressed()), this, SLOT(addDoteSlot()));
    connect(deleteDoteBtn, SIGNAL(pressed()), this, SLOT(deleteDoteSlot()));
    connect(changeDoteBtn, SIGNAL(pressed()), this, SLOT(changeDoteSlot()));

    connect(canvasW, SIGNAL(ready()), this, SLOT(ansTextSlot()));
}


void graphicsWidget::addDoteSlot(){
    bool ok1, ok2;
    doteAddXEdit->text().toFloat(&ok1);
    doteAddYEdit->text().toFloat(&ok2);
    if(ok1 && ok2){
        curDotesTEdit->setText("Calculating");
        calcSamp->addDote(QVector2D(doteAddXEdit->text().toFloat(), doteAddYEdit->text().toFloat()));
    }else{
        QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                             tr("Invalid adding point coordinates."));
    }
}

void graphicsWidget::changeDoteSlot(){
    bool ok1, ok2, ok3;
    float x = doteChangeXEdit->text().toFloat(&ok1);
    float y = doteChangeYEdit->text().toFloat(&ok2);
    int num = doteChangeEdit->text().toInt(&ok3);
    int length = calcSamp->getDoteCount();
    if( ok3 ){
        if (num <= length){
            if( ok2 && ok1){
                curDotesTEdit->setText("Calculating");
                QVector2D curDote(x, y);
                calcSamp->changeDote(num, curDote);
                //curDotesTEdit
            }else{
                QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                                     tr("Invalid changing dote coordinates."));
            }
        }else{
            QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                                 tr("Invalid changing dote number. Such dote doesn't exist"));
        }
    }else{
        QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                             tr("Invalid changing dote number."));
    }
}


void graphicsWidget::deleteDoteSlot(){
    bool ok;
    int num = doteDelEdit->text().toInt(&ok);
    int length = calcSamp->getDoteCount();
    if (ok){
        if (num <= length){
            curDotesTEdit->setText("Calculating");
            calcSamp->deleteDote(num);

        }else{
            QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                                 tr("Invalid deleting dote number. Such dote doesn't exist"));
        }
    }else{
        QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                             tr("Invalid deleting dote number."));
    }

}



void graphicsWidget::importSlot(){
    import();
}


//Импорт текстового файла с именем fileName
bool graphicsWidget::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        //Если приложение не может прочитать файл, информирование пользователя об ошибке через диалоговое окно
        QMessageBox::warning(this, tr("Bézier Curves Graph Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }
    //Импорт файла
    QTextStream in(&file);
    QString currentSt;
    float curFl1, curFl2;
    bool stat;
    while(! in.atEnd()){
        QVector2D cur;
        in>>(currentSt);
        curFl1 = currentSt.toFloat(&stat);
        if(stat){
            cur.setX(curFl1);

            if (! in.atEnd()){
                in>>(currentSt);
                curFl2 = currentSt.toFloat(&stat);
                if(stat){
                    cur.setY(curFl2);
                    //dotes.append(cur);
                    calcSamp->addDote(cur);
                }else{
                    QMessageBox::warning(this, tr("Bézier Curves Graph Application"), "Invalid dote data. The app can't find y dote value.");
                    return false;
                }
            }else{
                QMessageBox::warning(this, tr("Bézier Curves Graph Application"), "Invalid dote data. The app can't find y dote value.");
                return false;
            }

        }

    }
    return true;
}


/*
 * Слот для получения имени файла через диалоговое окно QFileDialog
 * Если пользователь выбрал файл для импортирования, имя файла передается в loadFile() для его загрузки в приложение
 * Добавлен фильтр для рассширений файлов (только txt)
 */
bool graphicsWidget::import() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("*.txt"));
    if (!fileName.isEmpty())
    {
    QTextStream in(&fileName);
    return loadFile(fileName);
    }
    return false;
}

/*
 * Тоже функция для импорта файла как и import.
 * Отличие в том, что функции передается предпологаемое имя текстового файла,
 * затем сразу идет проверка, что это действительно имя файла, затем проверка, что файл txt.
 * Функция используется для импорта при запуске приложения через командную строку
 */
bool graphicsWidget::importFile(QString fileName){
    if (!fileName.isEmpty())
    {
        QFileInfo fi(fileName);
        if(! fi.isFile()) {
            QMessageBox::warning(this, tr("Bézier Curves Graph Application"), "File not found. Please check the filename.");
            return false;
        }
        if (fi.completeSuffix() != "txt") {
            QMessageBox::warning(this, tr("Bézier Curves Graph Application"), "Cannot open this file type. Please import txt file.");
            return false;
        }
        loadFile(fileName);
        //textEdit->insertPlainText(in.readAll());
    }
    return true;
}



void graphicsWidget::ansTextSlot(){
    curDotesTEdit->setText(calcSamp->strAnswer());
}

void graphicsWidget::newSlot(){
    canvasW->removeAllFigures();
    calcSamp->clear();
    curDotesTEdit->setText("Please, enter elements values");
}

bool graphicsWidget::maybeExport(){
    if (curDotesTEdit->toPlainText() == "" || curDotesTEdit->toPlainText() == "Please, enter elements values"){
        return false;
    }
    return true;
}

bool graphicsWidget::exportSolution(){
    if (maybeExport()) {
        QFileDialog dialog(this);
        dialog.setAcceptMode(QFileDialog::AcceptSave);
        dialog.setFileMode(QFileDialog::AnyFile);
        dialog.setNameFilter("*.png");
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save file as"), QDir::currentPath(), tr("*.png"));
        return saveAs(fileName);
    }
    QMessageBox::warning(this, tr("Bézier Curves Graph Application"), "Nothing to export");
    return false;
}



/*
 * Экспорт решения в txt файл с именем fileName.
 * В случаях ошибок при попытке записать данные появиться диалоговое окно с errorMessage.
 */
bool graphicsWidget::saveAs(const QString &fileName) {
    if (fileName.isEmpty())
        errorMessage = tr("file address not specified");
    canvasW->exportPng(fileName);

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, tr("Bézier Curves Graph Applicationы"), errorMessage);
        errorMessage.clear();
        return false;
    }
    return true;
}



graphicsWidget::~graphicsWidget(){
    delete mainLayout;
    delete canvasW;
    //delete doteLayout;
    //delete doteXLabel;
}
