#include <fstream>
#include <iostream>
#include <string>
#include "City_Nodes.h"

using namespace std;

string menu(){
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
	cout<<"Please select from one of the choice below:"<<endl;
	cout<<"1. Transmit Message"<<endl;
	cout<<"2. Add new city"<<endl;
	cout<<"3. Help"<<endl;
	cout<<"4. Quit"<<endl;

	string choice;
	getline(cin,choice);
	return choice;
}

string loadMenu(){
	cout<<"Loading program..."<<endl;
	cout<<"Please enter the name of the coordinate file."<<endl;
	string fileName;
	while (1){
		getline(cin,fileName);
		ifstream inFileStream;
		string inLine;
		inFileStream.open(fileName);
		if (!inFileStream){cout<<"Could not read file.\nPlease enter the name correctly:\n(Maybe try 'cities.txt')\n";}
		else{break;}
	}
	cout<<"Successfully loaded program\n"<<endl;
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
	cout<<"Welcome to the messenger bird finding path program"<<endl;
	cout<<"In this post apocalyptic world, the best way to "<<endl;
	cout<<"communicate with other cities is through long range"<<endl;
	cout<<"messenger birds. This program will find the best route"<<endl;
	cout<<"for the bird to take and simulate the message "<<endl;
	cout<<"transmission."<<endl<<endl;
	return fileName;
}

int main(){
	City_Nodes runClass(loadMenu());
	while (1){
		string choice = menu();
		if (choice == "1"){
			cout<<"Prepare to send a message"<<endl;
		}
		else if (choice == "2"){
			cout<<"Prepare to add a city"<<endl;
		}
		else if (choice == "4"){
			cout<<"Shutting down."<<endl;
			return 0;
		}
		else {
			cout<<"\nERROR: Invalid input.\nPlease try again.\n"<<endl;
		}
	}
return 0;
}
