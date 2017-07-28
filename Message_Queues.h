#ifndef MESSAGE_QUEUES_H
#define MESSAGE_QUEUES_H

#include <string>
#include <iostream>

using namespace std;

struct Node{
    Node * next;
    string word;
};

class Message_Queues{
private:
    Node * start;
    Node * end;
    void QueueWord(string word);
public:
    Message_Queues();
    void printQueue();
    void QueueSentence(string sentece);
};
#endif // MESSAGE_QUEUES_H
