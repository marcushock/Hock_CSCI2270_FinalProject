#include <fstream>
#include <iostream>
#include <string>
#include "City_Nodes.h"

using namespace std;


//Main menu to be repeatedly displayed.
string menu(){
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
	cout<<"Please select from one of the choice below:"<<endl;
	cout<<"1. Transmit Message"<<endl;
	cout<<"2. Add new city"<<endl;
	cout<<"3. List cities"<<endl;
	cout<<"4. Help"<<endl;
	cout<<"5. Quit"<<endl;
	string choice;
	getline(cin,choice);
	return choice;
}

//Loading menu when first starting the program.
string loadMenu(){
	cout<<"Loading program..."<<endl;
	cout<<"Please enter the name of the coordinate file."<<endl;
	string fileName;
	while (1){
		getline(cin,fileName);
		ifstream inFileStream;
		string inLine;
		inFileStream.open(fileName);
		if (!inFileStream){cout<<"Could not read file.\nPlease enter the name correctly:\n(Maybe try entering 'cities.txt')\n";}
		else{break;}
	}
	cout<<"Successfully loaded program\n"<<endl;
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
	cout<<"Welcome to the messenger bird finding path program"<<endl;
	cout<<"In this post apocalyptic world, the best way to "<<endl;
	cout<<"communicate with other cities is through long range"<<endl;
	cout<<"messenger birds. This program will find the best route"<<endl;
	cout<<"for the bird to take and simulate the message "<<endl;
	cout<<"transmission."<<endl<<endl;
	return fileName;
}

void helpInfo(){
	cout<<"This program is to find a path to send a messenger bird that can fly 1,000 miles"<<endl;
	cout<<"before needing to rest in another city on the way to the destination."<<endl;
	cout<<"Dijkstra's algorithm is used to find the shortest distance."<<endl;
	cout<<"If the bird cannot make the journey, it will die and the message will be lost."<<endl;
	cout<<"The bird carries the message in a digital collar that displays one word at a "<<endl;
	cout<<"time. Therefore the message prints out one word at a time and is stored in "<<endl;
	cout<<"collar that deletes the message once displayed. "<<endl;
	cout<<"\nIf at any point you need to force close the program press 'Ctrl + C'"<<endl;
	cout<<"This program has input validation, however if you enter something non numeric "<<endl;
	cout<<"for a lattitude or longitude when entering a new city, the program WILL crash."<<endl;
	cout<<"Also, capitalization and spacing does matter when entering city names, so "<<endl;
	cout<<"be careful when inputting."<<endl;
	cout<<"\nFor any technical support please contact Marcus Hock"<<endl;
	cout<<"Email: marcus.hock@colorado.edu"<<endl;
}

//Simple loop to run all other functions from.
int main(){
	City_Nodes runClass(loadMenu());
	while (1){
		string choice = menu();
		if (choice == "1"){
			cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
			runClass.TransmitMessage();
		}
		else if (choice == "2"){
			cout<<"Prepare to add a city"<<endl;
			runClass.addCity();

		}
		else if (choice == "3"){
			runClass.printCities();
		}
		else if (choice =="4"){
			cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
			helpInfo();
		}
		else if (choice == "5"){
			cout<<"Shutting down."<<endl;
			return 0;
		}
		else {
			cout<<"\nERROR: Invalid input.\nPlease try again.\n"<<endl;
		}
	}
return 0;
}
