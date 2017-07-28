#include <climits>
#include "Message_Queues.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Message_Queues::Message_Queues(){
    start = nullptr;
    end = nullptr;
}

void Message_Queues::QueueWord(string word){
    Node * newNode = new Node;
    newNode -> word = word;
    if (start == nullptr){
        start = newNode;
    }
    if (end != nullptr){
        end -> next = newNode;
    }
    end = newNode;
    newNode -> next = nullptr;
}

void Message_Queues::QueueSentence(string inLine){
    istringstream mySS(inLine);
    string grab;
    cout<<"\nEncrypting message.."<<endl;
    while(getline(mySS, grab, ' ')) {
        QueueWord(grab);
    }
    cout<<"Message Encrypted"<<endl;
    return;
}

void Message_Queues::printQueue(){
    Node * temp = start;
    while (temp != nullptr){
        cout<<temp -> word<<endl;
        temp = temp -> next;
        delete start;
        start = temp;
    }
    start = nullptr;
    end = nullptr;
}
