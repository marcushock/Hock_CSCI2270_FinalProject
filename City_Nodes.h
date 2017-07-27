#ifndef CITY_NODES_H
#define CITY_NODES_H
#include <string>
#include <vector>

using namespace std;

struct City;
struct adjVector{
    City * v;
    double weight;
};

struct City{
    City(string _name, string _Lat, string _Long){
        Lat = stod(_Lat);
        Long = stod(_Long);
        name = _name;
    }
    City(){};
    double Lat;
    double Long;
    double distance;
    string name;
    bool solved;
    City * previous;
    vector <adjVector> adj;
};

class City_Nodes
{
    public:
        City_Nodes();
        City_Nodes(string inFile);
        virtual ~City_Nodes();
        void addCity(string name, double Lat, double Long);
        void findRoute(string name1, string name2);
        //void addCity()
        //void printDetails()
        //TransmitMessage
    protected:
    private:
        void Dijkstra(string name1, string name2);
        string * breakLine(string inLine);
        vector <City> cities;
        double checkDist(string name1, string name2);
        void addEdge(City name1, City name2, double weight);
        double range = 1000;

};

#endif // CITY_NODES_H
