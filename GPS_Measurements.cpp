#include <cmath>
#include "GPS_Measurements.h"
#include <iostream>
using namespace std;
GPS_Measurements::GPS_Measurements()
{
    //ctor
}

GPS_Measurements::~GPS_Measurements()
{
    //dtor
}
//This function uses the Haversine function to find the distnace along a great circle path. 
double GPS_Measurements::CalculateDistance(double Lat1, double Long1, double Lat2, double Long2)
{
    double rLat1 = Lat1/180.0*pi;
    double rLong1 = Long1/180.0*pi;
    double rLat2 = Lat2/180.0*pi;
    double rLong2 = Long2/180.0*pi;
    double a = sin((rLat1-rLat2)/2)*sin((rLat1-rLat2)/2)+cos(rLat1)*cos(rLat2)*sin((rLong1-rLong2)/2)*sin((rLong1-rLong2)/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    return c*r;
}
