#ifndef GPS_MEASUREMENTS_H
#define GPS_MEASUREMENTS_H


class GPS_Measurements
{
    public:
        GPS_Measurements();
        virtual ~GPS_Measurements();
        double CalculateDistance(double a, double b, double c, double d);
    protected:
    private:
        double pi = 3.14159265358979323846;
        double r = 3959; //Radius of the earth
};

#endif // GPS_MEASUREMENTS_H
