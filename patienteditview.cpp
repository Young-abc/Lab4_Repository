#include "patienteditview.h"
#include "ui_patienteditview.h"
#include <QDataWidgetMapper>
#include "idatabase.h"

PatientEditView::PatientEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard, tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbSpinHeight, tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->dbEditMobile, tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dbSpinWeight, tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbComboSex, tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbDateEditDOB, tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->dbCreatedTimeStamp, tabModel->fieldIndex("CREATEDTIMESTAMP"));

    dataMapper->setCurrentIndex(index);

    // 2. 核心修复：强制触发所有绑定控件的同步（关键！）
    dataMapper->submit(); // 先确认映射器状态
    dataMapper->revert(); // 触发控件从模型重新读取值
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

//保存
void PatientEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().submitPatientEdit();
    emit goPreviousView();
}

//取消
void PatientEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}

