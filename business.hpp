#ifndef business_hpp
#define business_hpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

class business
{
private:
    //members
    string name_;
    string address_;
    double latitude_;
    double longitude_;
    double stars_;
    unsigned review_count_;
    
public:
    //constructor
    business(){}
    business(const string name, const double latitude, const double longitude):
    name_(name),latitude_(latitude), longitude_(longitude){}
    ~business(){}
    
    string get_name() const{return name_;}
    
    //geolacation to coordinates on picture
    vector<double> get_location(){
        vector<double> geolocation(latitude_, longitude_);
        double m0 = -71.425;
        double n0 = 41.813;
        double m1 = -71.391;
        double n1 = 41.835;
        double x0 = 0, y0= 0, x1 = 10, y1 = 10;
        double x = (longitude_ - m0) / (m1-m0) * (x1-x0) + x0;
        double y = (latitude_ - n0) / (n1-n0) * (y1-y0) + y0;
        vector<double> location(x, y);
        return location;
    }
    
    
    
};

#endif /* business_hpp */
