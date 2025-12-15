#include "welcomeview.h"
#include "ui_welcomeview.h"
#include <QDebug>
WelcomeView::WelcomeView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeView)
{
    qDebug()<<"create WelcomeView";
    ui->setupUi(this);
}

WelcomeView::~WelcomeView()
{
    qDebug()<<"destroy WelcomeView";
    delete ui;
}

//医生管理
void WelcomeView::on_pushButton_2_clicked()
{
    emit doctorBtnClicked();
}

//科室管理
void WelcomeView::on_pushButton_clicked()
{
    emit departmentBtnClicked();
}

//患者管理
void WelcomeView::on_pushButton_3_clicked()
{
    emit patientBtnClicked();
}

