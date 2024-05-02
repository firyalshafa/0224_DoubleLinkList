// pertemuan9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct node {
    int noMhs;
    string name;
    node* next;
    node* prev;
};

node* START = NULL;

void addnode() {
    node* newnode = new node(); // step 1, create a new node 
    cout << "\nEnter the roll number of the student: ";
    cin >> newnode->noMhs;
    cout << "\nEnter the name of the  student:";
    cin >> newnode->name;

    if (START != NULL && newnode->noMhs == START->noMhs) {
        if (START != NULL && newnode->noMhs == START->noMhs) {
            cout << "\033 [31Duplicate roll numbers not allowed]\033[0m" << endl;
            return;
        }
        newnode->next = START;
        if (START != NULL) {
            START->prev = newnode;
        }
    }
}



int main()
{
    
}

