#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filter.h"
#include "business.h"
#include <string>
#include <QtDebug>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->map->legend->setVisible(true);
    ui->map->xAxis->grid()->setVisible(false);
    ui->map->yAxis->grid()->setVisible(false);
    QPixmap bkgnd(":/map.png");
    ui->map->setBackground(bkgnd);
    ui->map->setBackgroundScaledMode(Qt::IgnoreAspectRatio);
    ui->map->setBackgroundScaled(true);
    ui->map->axisRect()->setAutoMargins(QCP::msNone);
    ui->map->axisRect()->setMargins(QMargins(0,0,0,0));
    ui->map->xAxis->setRange(0, 5);
    ui->map->yAxis->setRange(0, 5);
//    ui->map->addGraph();

//    ui->map->graph(0)->setLineStyle(QCPGraph::lsNone);

    connect(ui->enter, SIGNAL(clicked(bool)), this, SLOT(on_enterButton_clicked()));
    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT(on_clearButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterButton_clicked(){
    string tag = ui->tag_co->text().toStdString();
    string res_num = ui->res_num_co->text().toUtf8().constData();
    string open_status = ui->open_co->currentText().toStdString();
    string latitude = ui->la_co->text().toStdString();
    string longitude = ui->la_co->text().toStdString();
    int distance = stoi(ui->dis_co->text().toStdString());

    vector<business> result = filter(res_num, open_status, tag, latitude, longitude, distance);

    QVector<double> x, y;
    int i=0;

    for(vector<business>::iterator it = result.begin(); it != result.end(); it++){
        ui->map->addGraph();
        ui->map->graph(i)->addData(it->get_location().at(0), it->get_location().at(1));
        ui->map->graph(i)->setScatterStyle(QCPScatterStyle::ssDisc);
        ui->map->graph(i)->addData(it->get_location()[0], it->get_location()[1]);
        ui->map->graph(i)->setName(QString::fromStdString(it->get_name()));
        ui->map->graph(i)->setPen(QColor(int(255/result.size())*i, 255-int(255/result.size())*i, int(255/result.size())*i));
        i++;
        ui->map->replot();

        qDebug() << "xx";
    }



}

void MainWindow::on_clearButton_clicked(){
    ui->tag_co->clear();
    ui->res_num_co->setValue(0);
    ui->open_co->setCurrentIndex(0);
    ui->la_co->setText("47");
    ui->lo_co->setText("-71.42");
    ui->dis_co->setText("0");
    for(int i=0; i<ui->map->graphCount(); i++)
        ui->map->clearGraphs();
    ui->map->replot();
}

