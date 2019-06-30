#include "find.h"
#include "ui_find.h"

find::find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::find)
{
    ui->setupUi(this);
//    this->find->setBackgroundRole(QPalette::Dark);

}

find::~find()
{
    delete ui;
}
