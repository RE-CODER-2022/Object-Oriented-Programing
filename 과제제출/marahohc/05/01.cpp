#include <iostream>
#include <cstring>
using namespace std;

class Queue;

class Node {
private:
    int data = 0;

public:
    Node* left = NULL;
    Node* right = NULL;
    Node() {
    }
    void setdata(int num) { data = num; }
    int getdata() { return data; }
};

class Tree {
private:
    Node* root = new Node;

public:
    Tree() {
        root->setdata(0);
    }
    Node* getRoot() { return root; }
    void maketree(int value) {
        Node* curnode = new Node;
        if (root->getdata() == 0) {
            root->setdata(value);
            return;
        }
        else {
            Node* newnode = root;
            curnode->setdata(value);
            while (newnode) {
                if (curnode->getdata() < newnode->getdata()) {
                    if (!newnode->left) {
                        newnode->left = curnode;
                        break;
                    }
                    newnode = newnode->left;
                }
                else if (curnode->getdata() > newnode->getdata()) {
                    if (!newnode->right) {
                        newnode->right = curnode;
                        break;
                    }
                    newnode = newnode->right;
                }
                else
                    break;
            }
        }
        return;
    }

    void Search(int num) {
        if (root->getdata() == 0) {
            cout << "Error 700" << endl;
            return;
        }
        else {
            Node* newnode = root;
            while (newnode) {
                if (newnode->getdata() > num) {
                    if (!newnode->left) {
                        cout << "Error 600" << endl;
                        return;
                    }
                    newnode = newnode->left;
                }
                else if (newnode->getdata() < num) {
                    if (!newnode->right) {
                        cout << "Error 600" << endl;
                        return;
                    }
                    newnode = newnode->right;
                }
                else {
                    cout << num << "is exists" << endl;
                    return;
                }
            }
        }
    }
    void PrintPre(Node* node) {
        if (node != NULL) {
            if (node->getdata() == 0) {
                cout << "Error 700" << endl;
                return;
            }
            else {
                cout << node->getdata() << "\t";
                PrintPre(node->left);
                PrintPre(node->right);
            }
        }
    }
    void PrintIn(Node* node) {
        if (node != NULL) {
            if (node->getdata() == 0) {
                cout << "Error 700" << endl;
                return;
            }
            else {
                PrintIn(node->left);
                cout << node->getdata() << "\t";
                PrintIn(node->right);
            }
        }
    }
    void PrintPost(Node* node) {
        if (node != NULL) {
            if (node->getdata() == 0) {
                cout << "Error 700" << endl;
                return;
            }
            else {
                PrintPost(node->left);
                PrintPost(node->right);
                cout << node->getdata() << "\t";
            }
        }
    }
    ~Tree() { delete root; }
};

class Queue {
private:
    int front = 0;
    int rear = 0;
    int maxSize = 6;
public:
    int arr[6] = { 0, };
    Queue() { };
    bool IsEmpty(void) {
        return !(front == rear);
    }
    bool IsFull(void) {
        return !(front == (rear + 1) % maxSize);
    }
    bool Enqueue(int num) {
        if (!IsFull()) {
            cout << "Error 300" << endl;
            return false;
        }
        else {
            rear = (rear + 1) % maxSize;
            arr[rear] = num;
            return true;
        }
    }
    bool Dequeue(Tree* tree, int num) {
        if (!IsEmpty()) {
            cout << "Error 400" << endl;
            return false;
        }
        else {
            if (rear - front >= num) {
                for (int i = front + 1; i <= front + num; i++) {
                    tree->maketree(arr[i]);
                    arr[i] = '\0';
                }
                front = (front + num) % maxSize;
            }
            else { // (rear < num)
                for (int i = front + 1; i != rear+1; ++i) {
                    i = i % maxSize;
                    tree->maketree(arr[i]);
                    arr[i] = '\0';
                }
                front = rear % maxSize;
            }
            return true;
        }
    }
    void PrintQueue(void) {
        if (arr[front + 1] == '\0') {
            cout << "Error 500" << endl;
            return;
        }
        for (int i = front + 1; i <= rear; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
        return;
    }

    ~Queue() {}
};

int main(void) {
    Tree maintree;
    char* command = new char;
    Queue mainqueue;
    int num = 0;

    while (1) {
        cout << "CMD>> ";
        cin.getline(command, 20); //enqueue 1
        char* fstcmd = strtok(command, " "); // enqueue
        if (fstcmd == NULL) {
            cout << "Error 100" << endl;
            continue;
        }
        char* seccmd = strtok(NULL, "\n "); //  1
        int secnum = 0;
        if(seccmd!=NULL)
            secnum = atoi(seccmd);
        if (!strcmp("Enqueue", fstcmd)) {
            char* thrcmd = strtok(NULL, " "); // 뒤에 더 오는 숫자
            if (seccmd == NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (!secnum) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (thrcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                mainqueue.Enqueue(secnum);
                continue;
            }
        }
        else if (!strcmp("Dequeue", fstcmd)) {
            char* thrcmd = strtok(NULL, " ");
            if (!secnum) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (thrcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                mainqueue.Dequeue(&maintree, secnum);
                continue;
            }
        }
        else if (!strcmp("Print_Queue", fstcmd)) {
            mainqueue.PrintQueue();
            continue;
        }
        else if (!strcmp("PRINT", fstcmd)) {
            if (seccmd == NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                if (!strcmp("PRE", seccmd)) {
                    maintree.PrintPre(maintree.getRoot());
                    cout << endl;
                    continue;
                }
                else if (!strcmp("IN", seccmd)) {
                    maintree.PrintIn(maintree.getRoot());
                    cout << endl;
                    continue;
                }
                else if (!strcmp("POST", seccmd)) {
                    maintree.PrintPost(maintree.getRoot());
                    cout << endl;
                    continue;
                }
                else {
                    cout << "Error 100" << endl;
                    continue;
                }
            }
        }
        else if (!strcmp("SEARCH", fstcmd)) {
            char* thrcmd = strtok(NULL, " ");
            if (!secnum) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (thrcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                maintree.Search(secnum);
                continue;
            }
            continue;
        }
        else if (!strcmp("EXIT", fstcmd)) {
            return 0;
        }
        else {
            cout << "Error 100" << endl;
            continue;
        }
    }
    delete command;
}