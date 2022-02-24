#include <iostream>
#include <cstring>
using namespace std;

class Node {
private:
    char* word = nullptr;
public:
    Node* left;
    Node* right;
    Node () {
        left = nullptr;
        right = nullptr;
    }
    void setword(char* WORD) { word = WORD; }
    char* getword() { return word; }
};

class BST {
private:
    Node* root = new Node;
public:
    Node* getroot(){return root;}
    void INSERT(char* word) {
        Node* curnode = new Node;
        if (root->getword() == nullptr) {
            root->setword(word);
            return;
        }
        else {
            Node* newnode = root;
            while (newnode) {
                if (root == NULL) {
                    root->setword(word);
                    return;
                }
                int curword= word[0]; //입력받은 단어의 맨 앞 글자
                int newword = newnode->getword()[0]; //트리에 있는 단어의 맨 앞 글자
                if (curword > newword) { // 입력받은 단어의 맨 앞글자가 후순
                    if (!newnode->left) { 
                        newnode->left = curnode;
                        return;
                    }
                    newnode = newnode->left;
                }
                else if (curword < newword) {// 트리노드 단어의 맨 앞글자가 후순
                    if (!newnode->right) {
                        newnode->right = curnode;
                        return;
                    }
                    newnode = newnode->right;
                }
                else if (curword == newword) { //두 단어의 앞 글자가 같을 때
                    int CUR = strlen(word);
                    int NEW = strlen(newnode->getword());
                    if (CUR > NEW) { //찾은 단어가 더 긴 경우
                        while (newnode) {
                            if (!newnode->left) {
                                newnode->left = curnode;
                                break;
                            }
                            newnode = newnode->left;
                        }
                        return;
                    }
                    else if (CUR < NEW) {//찾은 단어가 더 짧은 경우
                        while (newnode) {
                            if (!newnode->right) {
                                newnode->right = curnode;
                                break;
                            }
                            newnode = newnode->right;
                        }
                        return;
                    }
                }
                else
                    break;
            }
            return;
        }
    };
    void FIND(char* word) {
        Node* newnode = root;
        while (newnode) {
            int newwordfront = newnode->getword()[0];
            int wordfront = word[0];
            if (newwordfront > wordfront) { //노드 단어의 앞글자가 후순
                if (!newnode->left) {
                    cout << "Not found" << endl;
                    return;
                }
                else if (!strcmp(newnode->getword(), word)) { //같은 단어를 발견한 경우
                    cout<<word<<" exists"<<endl;
                    return;
                }
                newnode = newnode->left;
            }
            else if (newwordfront < wordfront) { //찾는 단어의 앞글자가 후순
                if (!newnode->right) {
                    cout << "Not found" << endl;
                    return;
                }
                else if (!strcmp(newnode->getword(), word)) { //같은 단어를 발견한 경우
                    cout << word << " exists" << endl;
                }
                newnode = newnode->right; 
            }
            else { //찾을 단어와 노드단어의 앞자리가 같은 경우
                if (!strcmp(newnode->getword(), word)) { //찾을 단어와 노드 단어의 앞자리가 같고 같은 단어인 경우
                    cout << word << " exists" << endl;
                    return;
                }
                else{
                    int CUR = strlen(word);               //찾을 단어의 길이와 
                    int NEW = strlen(newnode->getword()); //노드단어의 길이 비교
                    if (CUR < NEW) { //찾을 단어가 더 짧음
                        while (1) {
                            if (!newnode->left) {
                                cout << "Not found" << endl;
                                return;
                            }
                            else if (!strcmp(newnode->getword(), word)) {
                                cout << word << " exists" << endl;
                                return;
                            }
                            else
                                newnode = newnode->left;
                        }
                    }
                    else if (CUR > NEW) {//찾을 단어가 더 긴 경우
                        while (1) {
                            if (!newnode->right) {
                                cout << "Not found" << endl;
                                return;
                            }
                            else if (!strcmp(newnode->getword(), word)) {
                                cout << word << " exists" << endl;
                                return;
                            }
                            else
                                newnode = newnode->right;
                        }
                    }
                    else {//같은 길이의 다른 단어 cur == new
                        cout << "Not found" << endl;
                        return;
                    }
                }
            }
        }
    }
    void DELETE() {};
    void PrintPre(Node* node) {
        cout << node->getword() << "\t";
        PrintPre(node->left);
        PrintPre(node->right);
    }
    void PrintIn(Node* node) {
        PrintIn(node->left);
        cout << node->getword() << "\t";
        PrintIn(node->right);
    }
    void PrintPost(Node* node) {
        PrintPost(node->left);
        PrintPost(node->right);
        cout << node->getword() << "\t";
    }
};

int main(void) {
    char* command = new char;
    BST* word = new BST;
    while (1) {
        cin >> command;
        char* istword = new char;
        if (!strcmp("INSERT", command)) {
            cin >> istword;
            word->INSERT(istword);
            continue;
        }
        else if (!strcmp("FIND", command)) {
            cin >> istword;
            word->FIND(istword);
            continue;
        }
        else if (!strcmp("PRINT", command)) {
            cin >> istword;
            if (!strcmp("PRE", istword)) {
                word->PrintPre(word->getroot());
                continue;
            }
            else if (!strcmp("IN", istword)) {
                word->PrintIn(word->getroot());
                continue;
            }
            if (!strcmp("POST", istword)) {
                word->PrintPost(word->getroot());
                continue;
            }
        }
        else if (!strcmp("END", command)) {
            delete command;
            delete word;
            return 0;
        }
    }
}