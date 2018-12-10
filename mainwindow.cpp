#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterButton_clicked()
{
    QString Qcity=ui->type_name->text();
    //ui->label_7->setText(Qcity);
    //QString res=ui->result_num->text();
    //ui->label_7->setText(res);
    //QString res=ui->open_status->currentText();
    //ui->label_7->setText(res);
    //double_t res=ui->latitude_num->value();
    //ui->label_7->setNum(res);
    //double_t res=ui->longitude_num->value();
    //ui->label_7->setNum(res);
    QString res=ui->distance_num->currentText();
    ui->label_7->setText(res);
}



void MainWindow::on_result_num_valueChanged(const QString &resultNum)
{
    std::string utf8_text = resultNum.toUtf8().constData();
    QString qstr = QString::fromStdString(utf8_text);
    ui->label_7->setText(qstr);
}

void MainWindow::on_open_status_currentTextChanged(const QString &openStatus)
{
    std::string utf8_text = openStatus.toUtf8().constData();
    QString qstr = QString::fromStdString(utf8_text);
    ui->label_7->setText(qstr);
}

void MainWindow::on_clearButton_clicked()
{
    ui->type_name->clear();
    ui->result_num->setValue(1);
    ui->open_status->setCurrentIndex(0);
    ui->latitude_num->setValue(41.813);
    ui->longitude_num->setValue(-71.391);
    ui->distance_num->setCurrentIndex(0);
}
