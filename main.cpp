//
//  main.cpp
//  final_yelp
//
//  Created by Julia's Laptop on 12/8/18.
//  Copyright © 2018 Julia's Laptop. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>
#include "business.hpp"
#include <string>
#include <vector>
using namespace std;

vector<business> query(string tag = "", string res_cnt = "10", string is_open = "", string latitude = "47", string longitude = "-71.42", int distance = 2 )
{
    //open database
    sqlite3 *db;
    sqlite3_stmt * stmt;
    const char *zTail;
    int r = sqlite3_open("/Users/julia/Desktop/1/yelp.db",&db);
    if(r){
        printf("%s",sqlite3_errmsg(db));
    }
    else
        printf("open db sccess!\n");
    
    vector<business> res;
    string Q;
    double d_latitude = stod(latitude);
    double d_longitude = stod(longitude);
    //Look up business by name/tag, sort by stars desc
    if (tag != ""){
        const char *query1 = "select name, latitude, longitude from business where city = 'Providence' and state = 'RI' and ";
        const char *query2 = "name like '%";
        const char *query3 = "%' order by stars desc LIMIT ";
        string Query1(query1);
        string Query2(query2);
        string Query3(query3);
        if (is_open != ""){
            const char *q_open = "open = ";
            string Q_open(q_open);
            Q = Query1 + Q_open + is_open + string(" and ") + Query2 + tag + Query3 + res_cnt;
        }
        else{
            Q = Query1 + Query2 + tag + Query3 + res_cnt;
        }
    }
    //Look up distance(Manhattan) to a location by name/tag, sort by distance asc
    else {
        if (d_latitude >= 41.813 and d_latitude <= 41.835 and d_longitude >= -71.425 and d_longitude <= -71.391){
            const char *query1 = "SELECT name, latitude, longitude FROM ( SELECT business.name, business.open, business.latitude, business.longitude, abs(business.latitude-(";
            const char *query2 = ")) + abs(business.longitude-(";
            const char *query3 = ")) AS location FROM business ) AS x WHERE location < ";
            const char *query4 = " order by location asc limit ";
            string Query1(query1);
            string Query2(query2);
            string Query3(query3);
            string Query4(query4);
            std::string dis_temp = std::to_string(distance/0.7);
            if (is_open != "") {
                const char *q_open = " and open = ";
                string Q_open(q_open);
                Q = Query1 + latitude + Query2 + longitude + Query3 + dis_temp + Q_open + is_open + Query4 + res_cnt;
            }
            else{
                Q = Query1 + latitude + Query2 + longitude + Query3 + dis_temp + Query4 + res_cnt;
            }
        }
        else{
            //Get the businesses in Providence, RI, sort in stars
            cout << "INVALID INPUT" << endl;
            cout << "Display businesses in Providence, RI, sort in stars" << endl;
            const char *query1 = "select business.name from business where city = 'Providence' and state = 'RI' ";
            const char *query2 = " order by stars desc LIMIT ";
            string Query1(query1);
            string Query2(query2);
            if (is_open != ""){
                const char *q_open = "and open = ";
                string Q_open(q_open);
                Q = Query1 + Q_open + is_open + Query2 + res_cnt;
            }
            else{
                Q = Query1 + Query2 + res_cnt;
            }
        }
    }


    // execute query
    const char* full_q = Q.c_str();
    sqlite3_prepare(db,full_q ,-1,&stmt,&zTail);
    r = sqlite3_step(stmt);
    
    //get data
    const unsigned char * name;
    double la;
    double lo;
    while( r == SQLITE_ROW ){
        name = sqlite3_column_text( stmt,0 );
        la = sqlite3_column_double(stmt, 1);
        lo = sqlite3_column_double(stmt, 2);
        // push business object to vector
        std::string name_s(reinterpret_cast<const char*>(name));
        business x(name_s, la, lo);
        res.push_back(x);
        r = sqlite3_step(stmt);
        }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return res;
//    cout << res[0].get_name() << endl;
//    cout << res[1].get_name()<< endl;
}


int main(int argc, char **argv){
    //Get the businesses in Providence, RI, sort in stars
    vector<business> a = query();
    
//    Look up distance(Manhattan) to a location by name/tag, sort by distance asc
//    vector<business> a = query("", "10", "", "41.82", "-71.4", 2);

//    Look up business by name/tag, sort by stars desc, limit
//    vector<business> a = query("pizza");
    cout << a[0].get_name() << endl;
    cout << a[1].get_name()<< endl;
    return 0;
}
