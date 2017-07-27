#include "GPS_Measurements.h"

GPS_Measurements::GPS_Measurements()
{
    //ctor
}

GPS_Measurements::~GPS_Measurements()
{
    //dtor
}

GPS_Measurements::CalculateDistance(double Lat1, double Long1, double Lat2, double Long2)
{
    return (Lat1+Lat2+Long1+Long2);
}
