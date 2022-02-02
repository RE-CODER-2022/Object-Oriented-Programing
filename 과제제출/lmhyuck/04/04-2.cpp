#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

class Node {
private:
    int Data = 0;
public:
    Node* next;
    Node() { next = nullptr; }
    void setdata(int data) {
        Data = data;
    }
    int getdata() {
        return Data;
    }
    ~Node() {}
};

class List {
private:
    Node* head;
public:
    List() { head = nullptr;}
    int num = 0;
    int a = 0;
    void makerevolver() {
        head = new Node;
        head->setdata(1);
        Node* curr = head;
        for (int i = 0; i < 5; i++) {
            Node* inst = new Node;
            curr->next = inst;
            curr = inst;
        }
        curr->next = head;
    }
    void rotate(){
        a = rand() & 6 + 1;
        for (int i = 0; i < a; i++) {
            head = head->next;
        }
    }
    int checkbullet() {
        int c = head->getdata();
        if (c==1) {
            cout << "You Died..." << endl;
            return 1;
        }
        else {
            cout << "You Survived!" << endl;
            head = head->next;
            return 0;
        }
    }
    ~List() {
        Node* temp=head;
        while(head){
            temp=head;
            head=head->next;
            delete temp;
            temp=nullptr;
        }
        head=nullptr;
    }
};

int main() {
    List* list = new List();
    Node* head = nullptr;
    srand((unsigned int)time(NULL));
    int input = 0;
    string arr;
    string arr1 = "shoot";
    string arr2 = "rotate";
    cout << "Command list(shoot/rotate)" << endl;
    list->makerevolver();
    list->rotate();
    while (1) {
        cout << "CMD>> ";
        cin >> arr;
        if (arr == arr1)
            input = 1;
        else if (arr == arr2)
            input = 2;
        else
            input = 3;
        switch (input) {
        case 1:
            if (list->checkbullet())
                input = 4;
            break;
        case 2:
            list->rotate();
            system("clear");
            cout<<"Command list(shoot/rotate)"<<endl;
            break;
        case 3:
            cout << "Wrong Command!" << endl;
            break;
        }
        if (input == 4)
            break;
    }
    delete list;
    return 0;
}
