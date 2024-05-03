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
        newnode->prev = NULL;
        START = newnode;
    }
    else {
        node *current = START;
        node* previous->next;

        while (current != NULL && current->noMhs < newnode->noMhs)
        {
            previous = current;
            current = current->next;
        }
        newnode->next = current;
        newnode->prev = previous;

        if (current != NULL)
        {
            current->prev = newnode;
        }
        if (previous != NULL)
        {
            previous->next = newnode;
        }
        else
        {
            START = newnode;
        }
    }
}

bool search(int rollNo, node** previous, node** current)
{
    *previous = NULL;
    *current = START;
    while (current != NULL && (*current)-> noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
}

void deleteNode()
{
    node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;
    
    if (START == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL)
    {
        cout << "\033[31mThe record  with roll number" << rollNo << "not found\033[0m" << endl;
        return;
    }

    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }
    delete current;
    cout << "\x1b[32mRecod with roll number" << rollNo << "deleted\x1b[0m" << endl;    
}

bool listEmpty()
{
    return (START == NULL);
}

void traverse()
{
    if (listEmpty())
        cout << "\nlist is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        node* currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void revtraverse()
{
    if (listEmpty())
        cout << "\nlist is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are:" << endl;
        node* currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode << endl;
            currentNode = currentNode->prev;
        }
    }
}


void searchData()
{
    if (listEmpty() == true)
    {
        cout << "\nlist is empty" << endl;
    }
    node* prev, * curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search:";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord not found " << endl;
        cout << " \nRoll number : " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main()
{
    while (true)
    {
        try
        {
            cout << "\nMenu " << endl;
            cout << "1. add a record to the list" << endl;
            cout << "2. delete a record from the list " << endl;
            cout << "3. view all records in the ascending order of roll numbers" << endl;
            cout << "4. view a;; records in the descending order of roll numbers" << endl;
            cout << "5. search for record in the lis " << endl;
            cout << "6. exit " << endl;
            cout << "\nEnter your choise (1-6):";
            char ch;
            cin >> ch;

            switch (ch)
            {
            case'1' :
                addnode();
                break;

            case '2':
                deleteNode();
                break;
                
            case'3':
                traverse();
                break;
            }

        }

    }

}

