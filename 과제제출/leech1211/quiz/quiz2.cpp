#include <iostream>
using namespace std;


class Node
{
private:
    string value;
    Node* left;
    Node* right;
public:
    Node(string n)
    {
        this->value = n;
        left = nullptr;
        right = nullptr;
    }

    string getValue() {return value;}
    void setValue(string s) {this->value = s;}
    Node* getLeft() {return left;}
    Node* getRight() {return right;}
    void setLeft(Node* n) {this->left = n;}
    void setRight(Node* n) {this->right = n;}
};

class Tree
{
public:
    Node* root;
    Node* tail;
public:
    Node* getRoot() {return root;}
    Tree() :root(nullptr) {}
    void delTree(Node* pointer)                 //메모리 해제
    {
        if (pointer)
        {
            delTree(pointer->getLeft());
            delTree(pointer->getRight());
            delete pointer;
        }
    }

    void insertNode(string n)                   //insert
    {
        Node *node = new Node(n);
        Node *tmpRoot = nullptr;

        if (root == nullptr)
        {
            root = node;
        }
        else
        {
            Node *ptr = root;
            while (ptr != nullptr)
            {
                tmpRoot = ptr;
                if (node->getValue() < ptr->getValue())
                {
                    ptr = ptr->getLeft();
                }
                else if (node->getValue() > ptr->getValue())
                {
                    ptr = ptr->getRight();
                }
                else //값이 같으면 무시
                {
                    return;
                }
            }
            //넣을 위치에 대입
            if (node->getValue() > tmpRoot->getValue())
            {
                tmpRoot->setRight(node);
            }
            else
            {
                tmpRoot->setLeft(node);
            }
        }
    }

    void findNode(string n)                 //find
    {
        Node *ptr = root;

        while (ptr != nullptr)
        {
            if (ptr->getValue() == n)
            {
                cout << n << " exists" << endl;
                return;
            }
            else if (ptr->getValue() > n)
            {
                ptr = ptr->getLeft();
            }
            else
            {
                ptr = ptr->getRight();
            }
        }
        cout << "Not Found" << endl;
    }
    Node* searchMin(Node* n)
    {
        if(n == NULL)
            return NULL;
        
        if(n->getLeft() == NULL)
        {
            return n;
        }
        else
            return searchMin(n->getLeft());
    }

    Node* deleteNode(Node* node, Node* parent, string n)               //DELETE
    {
        if(node == nullptr)            //값이 없는 경우 
        {
            cout << "Not Found" << endl;
            return NULL;
        }
        else
        {
            Node *remove = NULL;
            //삭제할 노드 탐색
            if (node->getValue() > n)
            {
                remove = deleteNode(node->getLeft(), node, n);
            }
            else if (node->getValue() < n)
            {
                remove = deleteNode(node->getRight(), node, n);
            }
            else if (node->getValue() == n) //삭제할 노드를 찾은경우
            {
                remove = node;
                //삭제하려는 노드가 자식이 없는 단말노드일때
                //부모와의 연결을 끊는다
                if (node->getLeft() == NULL && node->getRight() == NULL)
                {
                    if (parent->getLeft() == node)
                        parent->setLeft(NULL);
                    if (parent->getRight() == node)
                        parent->setRight(NULL);
                }
                //삭제하려는 노드가 자식이 1개 있는 경우
                else if (node->getLeft() == NULL || node->getRight() == NULL)
                {

                    Node *temp;
                    if (node->getLeft() != NULL)
                    {
                        // temp->setValue((node->getLeft())->getValue());
                        temp = node->getLeft();
                    }
                    else
                    {
                        // temp->setValue((node->getRight())->getValue());
                        temp = node->getRight();
                    }

                    if (parent->getLeft() == node)
                    {
                        parent->setLeft(temp);
                    }
                    else
                    {
                        parent->setRight(temp);
                    }
                }
                //삭제하려는 노드가 자식이 2개 있는 경우
                else if (node->getLeft() != NULL && node->getRight() != NULL)
                {
                    Node *instead = searchMin(node->getRight());
                    instead = deleteNode(node, NULL, instead->getValue());
                    node->setValue(instead->getValue());
                }
            }
            return remove;
        }
        
    }

    void printNodePRE(Node *pointer) //전위
    {
        if (pointer)
        {
            cout << pointer->getValue() << " ";
            printNodePRE(pointer->getLeft());
            printNodePRE(pointer->getRight());
        }
    }
    void printNodeIN(Node *pointer) //중위
    {
        if (pointer)
        {
            printNodeIN(pointer->getLeft());
            cout << pointer->getValue() << " ";
            printNodeIN(pointer->getRight());
        }
    }
    void printNodePOST(Node *pointer) //후위
    {
        if (pointer)
        {
            printNodePOST(pointer->getLeft());
            printNodePOST(pointer->getRight());
            cout << pointer->getValue() << " ";
        }
    }
};

int main()
{
    Tree* t = new Tree;
    string commend;
    string word;
    string cmdkind; //print 형식

    while(1)
    {
        cin >> commend;
        if(commend == "END")
            break;
        else if(commend == "INSERT")
        {
            cin >> word;
            t->insertNode(word);
        }
        else if(commend == "DELETE")
        {
            cin >> word;
            t->deleteNode(t->getRoot(),NULL,word);
        }
        else if(commend == "FIND")
        {
            cin >> word;
            t->findNode(word);
        }
        else if(commend == "PRINT")
        {
            cin >> cmdkind;
            if(cmdkind == "PRE")
            {
                t->printNodePRE(t->getRoot());
                cout << endl;
            }
            else if(cmdkind == "POST")
            {
                t->printNodePOST(t->getRoot());
                cout << endl;
            }
            else
            {
                t->printNodeIN(t->getRoot());
                cout << endl;
            }
            
        }
        


    }
    t->delTree(t->getRoot());
    delete t;
}