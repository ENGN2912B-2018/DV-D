#ifndef business_hpp
#define business_hpp
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <QtDebug>

using namespace std;

class business
{
private:
    //members
    string name_;
    double latitude_;
    double longitude_;
    double stars_;
    string review_count_;

public:
    //constructor
    business(){}
    business(const double latitude, const double longitude):
    name_{"my_location"}, latitude_(latitude), longitude_(longitude){}
    business(const string name, const double latitude, const double longitude):
    name_(name),latitude_(latitude), longitude_(longitude){}
    ~business(){}

    string get_name() const{return name_;}
    double get_latitude() const{return latitude_;}
    double get_longitude() const{return longitude_;}
    double get_stars_() const{return stars_;}
    string get_review_count_() const{return review_count_;}

    //geolacation to coordinates on picture
    vector<double> get_location(){
        vector<double> geolocation(latitude_, longitude_);
        double m0 = -71.425;
        double n0 = 41.813;
        double m1 = -71.391;
        double n1 = 41.835;
        double x0 = 0, y0 = 0, x1 = 5, y1 = 5;
        double x = (longitude_ - m0) / (m1-m0) * (x1-x0) + x0;
        double y = (latitude_ - n0) / (n1-n0) * (y1-y0) + y0;
//        qDebug () << x << y;
        vector<double> location;
        location.push_back(x);
        location.push_back(y);
        return location;
    }



};

#endif /* business_hpp */
