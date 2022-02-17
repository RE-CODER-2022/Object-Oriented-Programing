#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Node {
private:
    int data = 0;
public:
    Node* left, * right;
    Node() {
        left = nullptr;
        right = nullptr;
    }
    void setData(int _data) { data = _data; }
    int getData() { return data; }
};

class Tree {
private:
    Node* root = new Node;
public:
    Tree() { root->setData(0); }
    Node* getRoot() { return root; }
    void MakeNode(int arr) { //Queue를 통해서 들어온 값을 BST형식에 맞게 넣어줌
        Node* curr = new Node;
        if (root->getData() == 0) {
            root->setData(arr);
            return;
        }
        else {
            Node* temp = root;
            curr->setData(arr);
            while (temp) {
                if (curr->getData() < temp->getData()) {
                    if (!temp->left) {
                        temp->left = curr; break;
                    }
                    temp = temp->left;
                }
                else if (curr->getData() > temp->getData()) {
                    if (!temp->right) {
                        temp->right = curr; break;
                    }
                    temp = temp->right;
                }
                else
                    break;
            }
        }
        return;
    }
    void Search(int fData) { //입력받은 값을 검색하는 메소드
        Node* temp = root;
        while (temp) {
            if (temp->getData() > fData) {
                if (!temp->left) {
                    cout << "Error 600" << endl;
                    return;
                }
                temp = temp->left;
            }
            else if (temp->getData() < fData) {
                if (!temp->right) {
                    cout << "Error 600" << endl;
                    return;
                }
                temp = temp->right;
            }
            else {
                cout << fData << " is exits" << endl;
                return;
            }
        }
    }
    void PrintPre(Node* node) { //Pre-Order방식으로 노드값을 출력
        if (node != NULL) {
            if (node->getData() == 0) {
                cout << "Error 700";
                return;
            }
            else {
                cout << node->getData() << "\t";
                PrintPre(node->left);
                PrintPre(node->right);
            }
        }
    }
    void PrintIn(Node* node) { //In-Order방식으로 노드값을 출력
        if (node != NULL) {
            if (node->getData() == 0) {
                cout << "Error 700";
                return;
            }
            else {
                PrintIn(node->left);
                cout << node->getData() << "\t";
                PrintIn(node->right);
            }
        }
    }
    void PrintPost(Node* node) { //Post-Order 방식으로 노드값을 출력
        if (node != NULL) {
            if (node->getData() == 0) {
                cout << "Error 700";
                return;
            }
            else {
                PrintPost(node->left);
                PrintPost(node->right);
                cout << node->getData() << "\t";
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
    int arr[6] = {};
    Queue() { }
    bool IsEmpty(void) {
        return !(front == rear);
    }
    bool IsFull(void) {
        return !(front == (rear + 1) % maxSize);
    }
    bool Enqueue(int x) {
        if (!IsFull()) {
            cout << "Error 300" << endl;
            return false;
        }
        else {
            rear = (rear + 1) % maxSize;
            arr[rear] = x;
            return true;
        }
    }//원형큐에 데이터값 저장
    bool Dequeue(Tree* tree, int num) { //큐에 있던 값들을 해당 개수 만큼 트리로 이동
        if (!IsEmpty()) {
            cout << "Error 400" << endl;
            return false;
        }
        else {
            if ((rear - front) >= num) {
                for (int i = front + 1; i <= front + num; i++) {
                    tree->MakeNode(arr[i]);
                    arr[i] = 0;
                }
                front = (front + num) % maxSize;
            }
            else {
                for (int i = front + 1; i <= rear; i++) {
                    i = i % maxSize;
                    tree->MakeNode(arr[i]);
                    arr[i] = 0;
                }
                front = rear % maxSize;
            }
            return true;
        }
    }
    void DisplayQueue(void) {
        if (arr[(front + 1)%maxSize] == 0) {
            cout << "Error 500" << endl;
            return;
        }
        for (int i = front + 1; i <= rear; i++) {
            cout << arr[i] << '\t';
        }
        cout << endl;
    } //Queue에 있는 모든 값 출력
    ~Queue() { }
};

int main() {
    Tree tree;
    Queue que;
    char* cmd = new char;
    while (1) {
        cout << "CMD>> ";
        cin.getline(cmd, 20);
        char* fcmd = strtok(cmd, " ");
        if (fcmd == NULL) {
        cout << "Error 100" << endl;
        continue;
        }
        char* scmd = strtok(NULL, " ");
        if (!strcmp("Enqueue", fcmd)) {
            char* tcmd = strtok(NULL, " ");
            if (scmd == NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (atoi(scmd)<1) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (tcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                que.Enqueue(atoi(scmd));
                continue;
            }
        }
        else if (!strcmp("Dequeue", fcmd)) {
            char* tcmd = strtok(NULL, " ");
            if (scmd == NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (atoi(scmd)<1) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (tcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                que.Dequeue(&tree, atoi(scmd));
                continue;
            }
        }
        else if (!strcmp("Print_Queue", fcmd))
            que.DisplayQueue();
        else if (!strcmp("SEARCH", fcmd)) {
            char* tcmd = strtok(NULL, " ");
            if (scmd == NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (atoi(scmd)<1) {
                cout << "Error 200" << endl;
                continue;
            }
            else if (tcmd != NULL) {
                cout << "Error 200" << endl;
                continue;
            }
            else {
                tree.Search(atoi(scmd));
                continue;
            }
        }
        else if (!strcmp("PRINT", fcmd)) {
            if (!strcmp("IN", scmd)) {
                tree.PrintIn(tree.getRoot());
                cout << endl;
                continue;
            }
            else if (!strcmp("PRE", scmd)) {
                tree.PrintPre(tree.getRoot());
                cout << endl;
                continue;
            }
            else if (!strcmp("POST", scmd)) {
                tree.PrintPost(tree.getRoot());
                cout << endl;
                continue;
            }
            else
                cout << "Error 200" << endl;
        }
        else if (!strcmp("EXIT", fcmd)) {
            return 0;
        }
        else {
            cout << "Error 100" << endl;
            continue;
        }
    }
    delete cmd;
    return 0;
}