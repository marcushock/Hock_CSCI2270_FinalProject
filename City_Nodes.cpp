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
    ifstream inFileStream;
    string inLine;
    inFileStream.open(fileName);
    if (!inFileStream){cout<<"Could not read file.\n";}
    while (getline(inFileStream,inLine)){
        string * dataArray;
        dataArray = breakLine(inLine);
        //cout<<dataArray[0]<<dataArray[1]<<dataArray[2]<<endl;
        City newCity(dataArray[0],dataArray[1],dataArray[2]);
        cities.push_back(newCity);
    }
    for (int q=0; q< cities.size();q++){
        for (int z= 0; z<cities.size(); z++){
            if (z!=q){
                GPS_Measurements calc;
                double distCalc = calc.CalculateDistance(cities[q].Lat, cities[q].Long, cities[z].Lat, cities[z].Long);
                if (distCalc <= range){
                    //cout<<"Add edge between "<<cities[q].name<<" and "<<cities[z].name<<" dist "<<distCalc<<endl;
                    addEdge(cities[q],cities[z],distCalc);
                }
            }
        }
    }
    Dijkstra("Seattle", "Denver");
}

void City_Nodes::addEdge(City name1, City name2, double weight){
    //The following code is modified from Shirly Montero-Quesada Example Dijkstra
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == name1.name){
            for(int j = 0; j < cities.size(); j++){
                if(cities[j].name == name2.name && i != j){
                    adjVector av;
                    av.v = &cities[j];
                    av.weight = weight;
                    cities[i].adj.push_back(av);
                }
            }
        }
    }
};

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


void City_Nodes::Dijkstra(string name1, string name2){
    if (name1==name2){
        cout<<"Same starting city. Message Terminated."<<endl;
        return;
    }
    int a;
    int b;
    int c = 0;
    int d = 0;
    for (int x = 0; x < cities.size(); x++){
        cities[x].distance = INT_MAX;
        cities[x].solved = false;
        cities[x].previous = nullptr;
        if (cities[x].name == name1){
            a = x;
            c = 1;
        }
        if (cities[x].name == name2){
            b = x;
            d = 1;
        }
    }
    if (d==0 || c == 0){
        cout<<"City(s) not found. Message Terminated."<<endl;
        return;
    }
    vector <City*> solved;
    City * prev;
    cities[a].solved = true;
    cities[a].distance = 0;
    solved.push_back(&cities[a]);
    City* solvedCity=nullptr;
    vector <City*> route;
    while (!cities[b].solved){
        double minDist = INT_MAX;
        for (int j =0; j<solved.size(); j++){
            City *current = solved[j];
            cout<<current ->name<<endl;
            for (int k =0; k < current->adj.size(); k++){
                double d = current->distance + current->adj[k].weight;
                if (current->adj[k].v->solved == false){
                    if (d < minDist){
                        solvedCity = current->adj[k].v;
                        prev = current;
                        minDist = d;
                    }
                }
            }

        }
        solved.push_back(solvedCity);
        solvedCity->distance = minDist;
        solvedCity->previous = prev;
        solvedCity->solved = true;
    }
    City * temp = &cities[b];
    while(temp!=nullptr){
        route.push_back(temp);
        temp = temp -> previous;
    }
    cout<<"Route"<<endl;
    for (int i = route.size()-1; i>=0; i--){
        cout<<route[i]->name<<" "<<endl;
    }
}
