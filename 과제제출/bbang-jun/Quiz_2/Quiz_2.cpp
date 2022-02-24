#include<iostream>
#include<cstring>
using namespace std;

class Node { // 노드
private:
    string word;
    Node* leftChild = NULL;
    Node* rightChild = NULL;

public:
    void setWord(string Word) { this->word = Word; }
    string getWord() { return this->word; }
    void setLeftChild(Node* snode) { leftChild = snode; } // 왼쪽 자식
    Node* getLeftChild() { return leftChild; }
    void setRightChild(Node* snode) { rightChild = snode; } // 오른쪽 자식
    Node* getRightChild() { return rightChild; }
};

class Tree { // 트리
private:
    Node* root = NULL; // rootNode의 초기값은 NULL
public:
    Node* getRoot() { return root; }
    void INSERT(Node* curnode, string word); // 삽입 함수
    void PRINT(string command); // 출력 함수
    void PRE(Node* curnode); // 전위 순회 함수
    void POST(Node* curnode); // 후위 순회 함수
    void IN(Node* curnode); // 중위 순회 함수
};

void Tree::INSERT(Node* curNode, string Word) { // 삽입 함수

    if (root == NULL) { // rootNode가 없을 때 
        Node* newNode = new Node;
        newNode->setWord(Word); // 단어
        newNode->setLeftChild(NULL); // 자식이 아직 없으므로 NULL
        newNode->setRightChild(NULL); // 자식이 아직 없으므로 NULL
        root = newNode; // 새로 생성된 노드가 rootNode가 된다.
    }

    // 첫번째 매개변수가 더 큰 경우 (strcmp 함수를 쓰기 위해 c_str()을 통하여 string 형을 char* 형으로 변환)
    // 첫번째 매개변수가 더 크면 1을 반환하는데 왜 "=1"은 안 되는지 찾아보기(식이 수정할 수 있는 lvalue여야 합니다.)
    else if (strcmp(curNode->getWord().c_str(), Word.c_str()) > 0) { 
        if (curNode->getLeftChild() == NULL) { // 왼쪽 자식이 없을 경우
            Node* newNode = new Node;
            newNode->setWord(Word);
            newNode->setLeftChild(NULL);
            newNode->setRightChild(NULL);
            curNode->setLeftChild(newNode);
        }
        else { // 왼쪽 자식이 있을 경우 INSERT 함수를 다시 실행함으로써 현재 노드의 위치를 왼쪽 자식으로 이동
            INSERT(curNode->getLeftChild(), Word);
        }
    }

    else if (strcmp(curNode->getWord().c_str(), Word.c_str()) < 0) { // 두번째 매개변수가 더 큰 경우
        if (curNode->getRightChild() == NULL) {
            Node* newNode = new Node;
            newNode->setWord(Word);
            newNode->setLeftChild(NULL);
            newNode->setRightChild(NULL);
            curNode->setRightChild(newNode);
        }
        else {
            INSERT(curNode->getRightChild(), Word);
        }
    }
}

void Tree::PRINT(string command) { // 출력 형식

    if (command == "PRE") {
        PRE(root);
    }
    else if (command == "POST") {
        POST(root);
    }
    else if (command == "IN") {
        IN(root);
    }
}

void Tree::PRE(Node* curNode) {

    if (curNode) {
        cout << curNode->getWord() << " ";
        PRE(curNode->getLeftChild());
        PRE(curNode->getRightChild());

    }
}

void Tree::POST(Node* curNode) {

    if (curNode) {
        POST(curNode->getLeftChild());
        POST(curNode->getRightChild());
        cout << curNode->getWord() << " ";
    }
}

void Tree::IN(Node* curNode) {

    if (curNode) {
        IN(curNode->getLeftChild());
        cout << curNode->getWord() << " ";
        IN(curNode->getRightChild());
    }
}

int main(void) 
{
    string command;
    string word;
    Tree* bst = new Tree;

    while (1) {
        cin >> command;

        if (command == "INSERT") {
            cin >> word;
            bst->INSERT(bst->getRoot(), word);
        }

        else if (command == "FIND") {
        }

        else if (command == "DELETE") {
        }

        else if (command == "PRINT") {
            cin >> word;
            bst->PRINT(word);
            cout << endl;
        }

        else if (command == "END") {
            break;
        }
    }

    delete bst;
}