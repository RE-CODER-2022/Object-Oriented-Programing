#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Bullet {
private:
    int bullet;
    Bullet* next;
public:
    Bullet() {
        bullet = 0;
        next = nullptr;
    }
    void setnext(Bullet* NEXT) { next = NEXT; }
    Bullet* getnext() { return next; }
    void setbullet(int num) { bullet = num; }
    int getbullet() { return bullet; }
};

class List {
private:
    Bullet* head;
    Bullet* tail;
public:
    List(void) {
        head = NULL;
        tail = NULL;
    }
    void MakeRevolver() {
        head = new Bullet;
        head->setbullet(1);
        Bullet* currbullet = head;

        for (int i = 0; i < 5; i++) {
            Bullet* newbullet = new Bullet;
            
            currbullet->setnext(newbullet);
            currbullet = newbullet;
        }
        currbullet->setnext(head);
    }

    int Shoot() {
        int num = head->getbullet();
        if (num == 1) {
            cout << "You Died..." << endl;
            return 1;
        }
        else {
            cout << "You Survived!" << endl;
            head = head->getnext();
            return 0;
        }
    }

    void Rotate() {
        srand((unsigned int)time(NULL));

        int num = rand() % 6 + 1;
        for (int i = 0; i < num; i++) {
            head = head->getnext();
        }
    }
};

int main(void) {
    char* command = new char;
    List* list = new List;
    int num = 0;
    cout << "Command list(shoot/rotate)" << endl;
   
    list->MakeRevolver();
    list->Rotate();
    while (1) {
        cout << "CMD>> ";
        cin >> command;
        if (!strcmp(command, "shoot")) {
            if (list->Shoot())
                return 0;
            
        }
        else if (!strcmp(command, "rotate")) {
            list->Rotate();
            system("clear");
        }
        else {
            cout << "Wrong Command!" << endl;
        }
    }
    return 0;
}