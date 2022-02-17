#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Node {
private:
    char data[20] = { '\0' };
public:
    Node* left, * right;
    Node() {
        left = nullptr;
        right = nullptr;
    }
    void setData(char* _data) { strcpy(data,_data); }
    char* getData() { return data; }
};

class Tree {
private:
    Node* root = new Node;
public:
    Tree() { root = NULL; }
    Node* getRoot() { return root; }
    void InsertWord(char* word) {
        Node* curr = new Node;
        if (!root) {
            root = curr;
            curr->setData(word);
            return;
        }
        else {
            Node* temp = root;
            curr->setData(word);
            while (temp) {
                if (strcmp(temp->getData(), curr->getData()) < 0) {
                    if (!temp->right)
                        temp->right = curr;
                    temp = temp->right;
                }
                else if (strcmp(temp->getData(), curr->getData()) > 0) {
                    if (!temp->left)
                        temp->left = curr;
                    temp = temp->left;
                }
                else
                    return;
            }
        }
    }
    void Find(char* fword) {
        Node* temp = root;
        while (temp) {
            if (strcmp(temp->getData(), fword) < 0) {
                if (!temp->right) {
                    cout << "Not found" << endl;
                    return;
                }
                temp = temp->right;
            }
            else if (strcmp(temp->getData(), fword) > 0) {
                if (!temp->left) {
                    cout << "Not found" << endl;
                    return;
                }
                temp = temp->left;
            }
            else if (strcmp(temp->getData(), fword) == 0) {
                cout << fword << " exists" << endl;
                return;
            }
            else
                return;
        }
    }
    void Delete(char* dword) {
        Node* prev = root;
        Node* temp = root;
        int count = 0;
        while (temp) {
            if (strcmp(temp->getData(), dword) < 0) {
                if (!temp->right) {
                    cout << "Not found" << endl;
                    return;
                }
                if (count > 0)
                    prev = prev->right;
                temp = temp->right;
                count++;
            }
            else if (strcmp(temp->getData(), dword) > 0) {
                if (!temp->left) {
                    cout << "Not found" << endl;
                    return;
                }
                if (count > 0)
                    prev = prev->left;
                temp = temp->left;
                count++;
            }
            else if (strcmp(temp->getData(), dword) == 0) {
                if (!temp->right && !temp->left) {
                    temp = NULL;
                }
                else {
                    prev->right = temp->right;
                    prev->left = temp->left;
                    temp = NULL;
                }
                return;
            }
        }
    }
    void PrintPre(Node* node) { //Pre-Order방식으로 단어를 출력
        if (node != NULL) {
            cout << node->getData() << "\t";
            PrintPre(node->left);
            PrintPre(node->right);
        }
        else
            return;
    }
    void PrintIn(Node* node) { //In-Order방식으로 단어를 출력
        if (node != NULL) {
            PrintIn(node->left);
            cout << node->getData() << "\t";
            PrintIn(node->right);
        }
        else
            return;
    }
    void PrintPost(Node* node) { //Post-Order방식으로 단어를 출력
        if (node != NULL) {
            PrintPost(node->left);
            PrintPost(node->right);
            cout << node->getData() << "\t";
        }
        else
            return;
    }
    ~Tree(){}
};

int main(void) {
    Tree tree;
    char* fcmd = new char;
    while (1) {
        cout << "입력:";
        cin >> fcmd;
        char* scmd = new char;
        if (!strcmp("END", fcmd)) {
            return 0;
        }
        if (!strcmp("INSERT", fcmd)){
            cin >> scmd;
            tree.InsertWord(scmd);
            continue;
        }
        else if (!strcmp("FIND", fcmd)) {
            cin >> scmd;
            tree.Find(scmd);
            continue;
        }
        else if (!strcmp("DELETE", fcmd)) {
            cin >> scmd;
            tree.Delete(scmd);
            continue;
        }
        else if (!strcmp("PRINT", fcmd)) {
            cin >> scmd;
            if (!strcmp("PRE", scmd)) {
                tree.PrintPre(tree.getRoot());
                cout << endl;
                continue;
            }
            else if (!strcmp("IN", scmd)) {
                tree.PrintIn(tree.getRoot());
                cout << endl;
                continue;
            }
            else if (!strcmp("POST", scmd)) {
                tree.PrintPost(tree.getRoot());
                cout << endl;
                continue;
            }
            else
                return 0;
        }
    }
    return 0;
}