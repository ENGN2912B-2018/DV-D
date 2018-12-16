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
    QColor legend_color = Qt::white;
    legend_color.setAlphaF(0);
    ui->map->legend->setBrush(legend_color);
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
    string longitude = ui->lo_co->text().toStdString();
    int distance = stoi(ui->dis_co->text().toStdString());
    string sort = ui->sort_co->currentText().toStdString();
    if(stod(longitude)<-71.425||stod(longitude)>-71.391||stod(latitude)<41.813||stod(latitude)>41.835){
        new_win2 = new Form2;
        new_win2->show();
    }
    else{
        vector<business> result = filter(res_num, open_status, tag, latitude, longitude, distance, sort);
        if(result.size()==0){
            new_win = new Form;
            new_win->show();
            }
        else{
            int i=0;
            for(vector<business>::iterator it = result.begin(); it != result.end(); it++){
                if(it->get_longitude()>-71.425&&it->get_longitude()<-71.391&&it->get_latitude()>41.813&&it->get_longitude()<41.835){
                    ui->map->addGraph();
                    ui->map->graph(i)->addData(it->get_location()[0], it->get_location()[1]);
                    ui->map->graph(i)->setScatterStyle(QCPScatterStyle::ssDisc);
                    ui->map->graph(i)->setName(QString::fromStdString(it->get_name()));
                    ui->map->graph(i)->setPen(QColor(int(255/result.size())*i, 255-int(255/result.size())*i, int(255/result.size())*i));
                    i++;
                    ui->map->replot();
                    qDebug() << it->get_latitude(); qDebug() << it->get_longitude();
                    qDebug() << it->get_location()[0] << it->get_location()[1];
                }
            }
            business my_location(stod(latitude), stod(longitude));
            ui->map->addGraph();
            ui->map->graph(i)->addData(my_location.get_location()[0], my_location.get_location()[1]);
            ui->map->graph(i)->setScatterStyle(QCPScatterStyle::ssDisc);
            ui->map->graph(i)->setName("my location");
            ui->map->graph(i)->setPen(QColor(0, 0, 0));
            ui->map->replot();
//            qDebug() << my_location.get_location()[0];
//            qDebug() << my_location.get_location()[1];
        }
    }
}

void MainWindow::on_clearButton_clicked(){
    ui->tag_co->clear();
    ui->res_num_co->setValue(1);
    ui->open_co->setCurrentIndex(0);
    ui->la_co->setText("41.82");
    ui->lo_co->setText("-71.42");
    ui->dis_co->setText("1");
    for(int i=0; i<ui->map->graphCount(); i++)
        ui->map->clearGraphs();
    ui->map->replot();
}

