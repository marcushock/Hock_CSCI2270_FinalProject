#include "City_Nodes.h"
#include <iostream>
#include <string>
#include <fstream>
#include "GPS_Measurements.h"
#include <vector>
#include <climits>
#include <sstream>

using namespace std;



City_Nodes::City_Nodes(){//ctor
}

City_Nodes::City_Nodes(string fileName){//ctor
    cout<<"we rank"<<endl;
    ifstream inFileStream;
    string inLine;
    inFileStream.open(fileName);
    if (!inFileStream){cout<<"Could not read file.\n";}
    while (getline(inFileStream,inLine)){
        string * dataArray;
        dataArray = breakLine(inLine);
        cout<<dataArray[0]<<dataArray[1]<<dataArray[2]<<endl;
        City newCity(dataArray[0],dataArray[1],dataArray[2]);
        cout<<"This too"<<endl;
        cities.push_back(newCity);
    }
    for (int q; q< cities.size();q++){
        cout<<cities[q].name<<endl;
        cout<<
    }
}

string * City_Nodes::breakLine(string inLine){
    string * info = new string[3];
    istringstream mySS(inLine);
    int i = 0;
    string grab;
    while(getline(mySS, grab, ',')) {
        info[i] = grab;
        i++;
    }
    return info;
};


City_Nodes::~City_Nodes(){//dtor
}

void City_Nodes::addCity(string name, double Lat, double Long){
    return;
};
