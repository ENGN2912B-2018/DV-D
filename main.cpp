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

void query( string city = "", string state = "", string res_cnt = "10", string is_open = "1", string tag = "", string latitude = "", string longitude = "", int distance = 0 )
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
    
    string Q;
    //Look up business by name/tag, sort by stars desc, limit
    if (tag != ""){
        const char *query1 = "select name, latitude, longitude from business where business.open = ";
        const char *query2 = " and business.name = '";
        const char *query3 = "' order by stars desc LIMIT ";
        string Query1(query1);
        string Query2(query2);
        string Query3(query3);
        Q = Query1 + is_open + Query2 + tag + Query3 + res_cnt;
    }
    //Look up distance(Manhattan) to a location by name/tag, sort by distance asc
    else if (latitude != ""){
        const char *query1 = "SELECT name, latitude, longitude FROM ( SELECT business.name, business.open, business.latitude, business.longitude, abs(business.latitude-(";
        const char *query2 = ")) + abs(business.longitude-(";
        const char *query3 = ")) AS location FROM business ) AS x WHERE location < ";
        const char *query4 = " and open = ";
        const char *query5 = " order by location asc limit ";
        string Query1(query1);
        string Query2(query2);
        string Query3(query3);
        string Query4(query4);
        string Query5(query5);
        std::string dis_temp = std::to_string(distance/70.0);
        Q = Query1 + latitude + Query2 + longitude + Query3 + dis_temp + Query4 + is_open + Query5 + res_cnt;
    }
    //Get the businesses in Providence, RI, sort in stars
    else{
        const char *query1 = "select business.name from business where city = 'Providence' and state = 'RI' and open = ";
        const char *query2 = " order by stars desc LIMIT ";
        string Query1(query1);
        string Query2(query2);
        Q = Query1 + is_open + Query2 + res_cnt;
    }
    const char* full_q = Q.c_str();
    sqlite3_prepare(db,full_q ,-1,&stmt,&zTail);
    
    r = sqlite3_step(stmt);
    const unsigned char * name;
    double la;
    double lo;
    vector<business> res;
    while( r == SQLITE_ROW ){
        name = sqlite3_column_text( stmt,0 );
        la = sqlite3_column_double(stmt, 1);
        lo = sqlite3_column_double(stmt, 2);
        std::string name_s(reinterpret_cast<const char*>(name));
        business x(name_s, la, lo);
        res.push_back(x);
        r = sqlite3_step(stmt);
        }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    cout << res[0].get_name() << endl;
    cout << res[1].get_name()<< endl;
}


int main(int argc, char **argv){
    query();
    return 0;
}
