//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#include "business.h"
#include <string>
#include <vector>
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <iostream>
#include <QDir>
#include <QMessageBox>
using namespace std;


vector<business> filter(string res_cnt = "10", string is_open = "", string tag = "", string latitude = "47", string longitude = "-71.42", int distance = 2, string rank = "distance")
{
    //open database
    qDebug()<<"current currentPath: "<<QDir::currentPath();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //    QString c = QCoreApplication::applicationDirPath();
    //    db.setDatabaseName(c + "/yelp.db");
    //    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    qDebug()<<"current currentPath: "<<QDir::currentPath();
    QDir temDir("../../../../DV-D-master/yelp.db");
    QString filePath = temDir.absolutePath();
//    qDebug(qUtf8Printable(filePath));
//    QString filePath = QDir::currentPath();
//    QString file_path = dir_path + "/../../yelp.db";
//    QMessageBox::warning(0, "PATH", filePath, QMessageBox::Yes);
    db.setDatabaseName(filePath);
    if( !db.open() )
    {
        qDebug() << db.lastError();
        qDebug( "Failed to connect." );
    }
    qDebug( "Connected!" );
    
    vector<business> res;
    string Q;
    string query1 = "SELECT name, latitude, longitude, review_count, stars, open, distance FROM ( SELECT business.name, business.review_count, business.stars, business.open, business.latitude, business.longitude, abs(business.latitude-(";
    string query2 = ")) + abs(business.longitude-(";
    string query3 = ")) AS distance FROM business ) AS x WHERE longitude > -71.425 and longitude < -71.391 and latitude > 41.813 and latitude < 41.835 and distance < ";
    std::string dis_temp = std::to_string(distance/0.7);
    Q += query1 + latitude + query2 + longitude + query3 + dis_temp;
    if (tag != ""){
        Q += " and name like '%" + tag + "%' ";
    }
    if (is_open != "") {
        string q_open = " and open = ";
        Q += q_open + is_open;
    }
    if (rank == "distance"){
        Q += " order by " + rank + " asc limit " + res_cnt;
    }
    else{
        Q += " order by " + rank + " desc limit " + res_cnt;
    }


//    qDebug() << QString::fromStdString(Q);
    QSqlQuery qry;
    QString Qry = QString::fromStdString(Q);
    qry.prepare(Qry);
    if( !qry.exec() ){
        qDebug( "!" );
        qDebug() << qry.lastError();
    }
    else
    {
        qDebug( "Selected!" );
        QSqlRecord rec = qry.record();
        
//        for( int c=0; c<cols; c++ )
//            qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; qry.next(); r++ ){
            QString r_name = qry.value(0).toString();
            double rlatitude = qry.value(1).toDouble();
            double rlongitude = qry.value(2).toDouble();
            string rname = r_name.toStdString();
            business x(rname, rlatitude, rlongitude);
            res.push_back(x);
//            qDebug() << QString( "NAME %1, LA %2, LO %3" ).arg(qry.value(0).toString()).arg(qry.value(1).toDouble()).arg(qry.value(2).toDouble());
        }
    }
    db.close();
//    qDebug() << res.size();
    return res;
}
