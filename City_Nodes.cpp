#include "Message_Queues.h"
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
        City newCity(dataArray[0],dataArray[1],dataArray[2]);
        cities.push_back(newCity);
    }
    for (int q=0; q< cities.size();q++){
        for (int z= 0; z<cities.size(); z++){
            if (z!=q){
                GPS_Measurements calc;
                double distCalc = calc.CalculateDistance(cities[q].Lat, cities[q].Long, cities[z].Lat, cities[z].Long);
                if (distCalc <= range){
                    addEdge(cities[q],cities[z],distCalc);
                }
            }
        }
    }
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


void City_Nodes::Dijkstra(string name1, string name2){
    sent = false;
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
    int limitCount=0;
    if (cities[a].adj.size() == 0 || cities[b].adj.size() == 0){
        cout<<"Cities not connected. Messenger bird died."<<endl;
        return;
    }
    while (!cities[b].solved){
        if (limitCount >= 1000){
            cout<<"Cities not connected. Messenger bird died."<<endl;
            return;
        }
        limitCount ++;
        double minDist = INT_MAX;
        for (int j =0; j<solved.size(); j++){
            City *current = solved[j];
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
    cout<<"The shortest route is: "<<endl;
    for (int i = route.size()-1; i>=0; i--){
        if (i==0){
            cout<<route[i]->name<<endl;
        }
        else{
            cout<<route[i]->name<<" ==> ";
        }
    }
    cout<<"The total distance flown is "<<cities[b].distance<<" miles."<<endl;
    sent = true;
}

void City_Nodes::TransmitMessage(){
    cout<<"Type in starting city name:"<<endl;
    string name1;
    bool check = false;
    while (1){
        getline(cin, name1);
        for (int x = 0; x < cities.size(); x++){
            if (cities[x].name == name1){
                check = true;
            }
        }
        if (check){
            break;
        }
        else{
            cout<<"City not found. Please enter a valid city."<<endl;
        }
    }
    cout<<"\nType in destination city name:"<<endl;
    string name2;
    check = false;
    while (1){
        getline(cin, name2);
        for (int x = 0; x < cities.size(); x++){
            if (cities[x].name == name2){
                check = true;
            }
        }
        if (check){
            break;
        }
        else{
            cout<<"City not found. Please enter a valid city."<<endl;
        }
    }
    string inMessage;
    cout<<"\nPlease enter a message to encrypt and send:"<<endl;

    while (1){
        getline(cin, inMessage);
        if (inMessage != ""){
            break;
        }
        cout<<"Please enter a valid character or message"<<endl;
    }
    Message_Queues message;
    message.QueueSentence(inMessage);
    cout<<"\nPress the enter key to send message (bird)."<<endl;
    cin.get();
    Dijkstra(name1, name2);
    if (sent){
        cout<<"\nMessage received."<<endl;
        cout<<"Press the enter key to open the message"<<endl;
        cin.get();
        message.printQueue();

    }
    cout<<endl;
    cout<<"Press enter to return to the main menu"<<endl;
    cin.get();
    cout<<endl;
}

void City_Nodes::addCity(){
    cout<<"\nPlease enter a city name:"<<endl;
    string name;
    while (1){
        getline(cin, name);
        bool flag = true;
        if (name =="q"){
            cout<<"Cancelling...\n"<<endl;

            return;
        }
        for (int x = 0; x<cities.size(); x++){
            if (cities[x].name==name){
                flag = false;
            }
        }
        if (name != "" && flag){
            break;
        }
        cout<<"Please enter a valid city name that has not been used before and is at least \none character."<<endl;
        cout<<"Or if you would like to cancel, enter 'q'"<<endl;
    }
    string sLat;
    double Lat;
    cout<<"\nPlease enter the lattitude coordinate. South should be negative"<<endl;
    while (1){
        getline(cin, sLat);
        bool flag = true;
        Lat = stod(sLat);
        if (name != "" && Lat<=90.0 && Lat >=-90.0){
            break;
        }
        cout<<"Please enter a valid lattitude value"<<endl;
    }
    string sLong;
    double Long;
    cout<<"\nPlease enter the longitude coordinate. West should be negative"<<endl;
    while (1){
        getline(cin, sLong);
        bool flag = true;
        Long = stod(sLong);
        if (name != "" && Long<=190.0 && Long >=-180.0){
            break;
        }
        cout<<"Please enter a valid longitude value"<<endl;
    }
    City newCity(name, sLat, sLong);
    cities.push_back(newCity);
    cout<<newCity.name<<endl;
    for (int x = 0; x< cities.size()-1;x++){
        GPS_Measurements calc;
        double distance = calc.CalculateDistance(Lat, Long, cities[x].Lat, cities[x].Long);
        if (distance <= range){
            addEdge(cities[cities.size()-1], cities[x], distance);
            addEdge(cities[x], cities[cities.size()-1], distance);
        }
    }
}


void City_Nodes::printCities(){
    for (int x=0; x < cities.size(); x++){
        cout<<cities[x].name<<" is at "<<cities[x].Lat<<", "<<cities[x].Long<<endl;
    }
    cout<<endl;
};
