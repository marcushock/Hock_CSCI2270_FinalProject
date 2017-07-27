#include <fstream>
#include <iostream>
#include <string>
#include "City_Nodes.h"

using namespace std;

string menu(){
	cout<<"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"<<endl;
	cout<<"Welcome"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
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
	cout<<"Successfully loaded program"<<endl;
	return fileName;
}

int main(){
	City_Nodes runClass(loadMenu());
	menu();
return 0;
}
