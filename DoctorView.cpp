#include "DoctorView.h"
#include "ui_DoctorView.h"

Doctor::Doctor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Doctor)
{
    ui->setupUi(this);
}

Doctor::~Doctor()
{
    delete ui;
}
