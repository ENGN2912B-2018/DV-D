#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
using namespace std;


vector<business> filter( string res_cnt = "10", string is_open = "", string tag = "", string latitude = "47", string longitude = "-71.42", int distance = 2 )
{
    //open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/DeathPrison/Documents/C++/yelp.db");
    if( !db.open() )
    {
        qDebug() << db.lastError();
        qDebug( "Failed to connect." );
    }
    qDebug( "Connected!" );
    
    vector<business> res;
    string Q;
    double d_latitude = stod(latitude);
    double d_longitude = stod(longitude);
//    Look up business by name/tag, sort by stars desc, limit
    if (tag != ""){
        qDebug() << "first";
        string query1 = "select name, latitude, longitude from business where city = 'Providence' and state = 'RI' and ";
        string query2 = "name like '%";
        string query3 = "%' order by stars desc LIMIT ";
        if (is_open != ""){
            string q_open = "open = ";
            Q = query1 + q_open + is_open + string(" and ") + query2 + tag + query3 + res_cnt;
        }
        else{
            Q = query1 + query2 + tag + query3 + res_cnt;
        }
    }
    else if(d_latitude >= 41.813 and d_latitude <= 41.835 and d_longitude >= -71.425 and d_longitude <= -71.391){
        qDebug() << "Second";
        string query1 = "SELECT name, latitude, longitude FROM ( SELECT business.name, business.open, business.latitude, business.longitude, abs(business.latitude-(";
        string query2 = ")) + abs(business.longitude-(";
        string query3 = ")) AS location FROM business ) AS x WHERE location < ";
        string query4 = " order by location asc limit ";
        std::string dis_temp = std::to_string(distance/0.7);
        if (is_open != "") {
            string q_open = " and open = ";
            Q = query1 + latitude + query2 + longitude + query3 + dis_temp + q_open + is_open + query4 + res_cnt;
        }
        else{
            Q = query1 + latitude + query2 + longitude + query3 + dis_temp + query4 + res_cnt;
        }
    }
    else{
//        Get the businesses in Providence, RI, sort in stars
        qDebug() << "Third";
        string query1 = "select name, latitude, longitude from business where city = 'Providence' and state = 'RI' ";
        string query2 = " order by stars desc LIMIT ";
        if (is_open != ""){
            string q_open = "and open = ";
            Q = query1 + q_open + is_open + query2 + res_cnt;
        }
        else{
            Q = query1 + query2 + res_cnt;
        }
    }
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
            qDebug() << QString( "NAME %1, LA %2, LO %3" ).arg(qry.value(0).toString()).arg(qry.value(1).toDouble()).arg(qry.value(2).toDouble());
//            qDebug() << QString( "NAME %1" ).arg(qry.value(0).toString());

        }
    }
    db.close();
    qDebug() << res.size();
    return res;
}
