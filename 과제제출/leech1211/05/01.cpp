#include <iostream>
#include <cstring>
using namespace std;

class Node
{
private:
    int value;
    Node* left;
    Node* right;
public:
    Node(int n)
    {
        this->value = n;
        left = nullptr;
        right = nullptr;
    }

    int getValue() {return value;}
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
    void insertNode(int data);
    void searchNode(int data);
    void printNodePRE(Node* n);
    void printNodeIN(Node* n);
    void printNodePOST(Node* n);
    void printNodeEmptyCheck(Node* n,string cmd);

    Tree() :root(nullptr) {}
    void delTree(Node* pointer)
    {
        if (pointer)
        {
            delTree(pointer->getLeft());
            delTree(pointer->getRight());
            delete pointer;
        }
    }
    friend class Queue;
};


class Queue
{
public:
    int front;
    int rear;
    int size;
    int* arr;
    int count;
public:
    Queue()
    {
        size = 5;           // maximum size of Queue is 5
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;           //큐의 인덱스의 개수
        //cout << "constructor" << endl;
    }
    ~Queue()
    {
        delete[] arr;
    }
    bool isFull()                                                 //큐가 다 찼는가?
    {
        if(count == 0)                                             //아무것도 없는상태
        {
            return false;
        }
        else if((rear) % size == front)                           //rear + 1 % size == front
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Enqueue(int number)                                            //삽입
    {
        if(!(isFull()))
        {
            arr[rear] = number;
            rear = (rear + 1) % size;
            count++;
        }
        else                                                        //큐가 다찼을때 오류코드 채워주세용~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!
        {
            cout << "Error 300" << endl;
        }
    }
    void Dequeue(int number, Tree* t)                                       //전달인자는 몇개의 숫자를 지울것인지
    {
        int data;
        if(count < number)
            number = count;
        
        if(number >= 0)
        {
            if (number == 0)
            {
                cout << "Error 400" << endl; //큐가 비었을때 요류코드 채워주세요~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!
            }
            else
            {
                for (int i = 0; i < number; i++)
                {
                    if (count > 0)
                    {
                        data = arr[(front) % (size)];
                       // cout << "data: " << data << endl;
                        t->insertNode(data);
                        front = (front + 1) % size;
                        count--;
                    }
                }
            }
            
        }
    }
    void printQ()                                                   //출력
    {
        int idx = 0;
        idx = front % size;
        do
        {
            if (count == 0)
            {
                cout << "Error 500";                       //큐가 비었을때 요류코드 채워주세요~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!
                break;
            }
            else if((idx + 1) % size != rear)
            {
                printf("%d ", arr[idx % size]);
                idx++;
            }
            else if ((idx + 1) % size == rear)
            {
                printf("%d ", arr[idx % size]);
                break;
            }
                
            
        } while (1);
    }
};

void Tree::insertNode(int n)
{
    Node* node = new Node(n);
    Node* tmpRoot = nullptr;

    if(root == nullptr)
    {
        root = node;
    }
    else
    {
        Node* ptr = root;
        while(ptr != nullptr)
        {
            tmpRoot = ptr;
            if(node->getValue() < ptr->getValue())
            {
                ptr = ptr->getLeft();
            }
            else if(node->getValue() > ptr->getValue())
            {
                ptr = ptr->getRight();
            }
            else    //값이 같으면 무시
            {
                return ;
            }
        }
        //넣을 위치에 대입
        if(node->getValue() > tmpRoot->getValue())
        {
            tmpRoot->setRight(node);
        }
        else
        {
            tmpRoot->setLeft(node);
        }
    }
    
}

void Tree::searchNode(int n)
{
    Node* ptr = root;

    while(ptr != nullptr)
    {
        if(ptr->getValue() == n)
        {
            cout << n << "is exists" << endl;
            return;
        }
        else if(ptr->getValue() > n)
        {
            ptr = ptr->getLeft();
        }
        else
        {
            ptr = ptr->getRight();
        }
    }
    cout << "Error 600" << endl;                                                       //트리에서 찾았는데 값이 없는경우 에러코드 넣어주세요~~~~~~~~~~~~~~~~~~~~!!
}

void Tree::printNodePRE(Node* pointer)             //전위
{
    if(pointer)
    {
        cout << pointer->getValue() << " " ;
        printNodePRE(pointer->getLeft());
        printNodePRE(pointer->getRight());
    }

}
void Tree::printNodeIN(Node* pointer)              //중위
{
    if(pointer)
    {
        printNodeIN(pointer->getLeft());
        cout << pointer->getValue() << " " ;
        printNodeIN(pointer->getRight());
    }
}
void Tree::printNodePOST(Node* pointer)              //후위
{
    if(pointer)
    {
        printNodePOST(pointer->getLeft());
        printNodePOST(pointer->getRight());
        cout << pointer->getValue() << " " ;
    }
}
void Tree::printNodeEmptyCheck(Node* n,string cmd)      //일단 Tree가 비었는지 확인
{
    if(n == nullptr)
    {
        cout << "Error 700" << endl;
    }
    if(cmd == "PRE")
    {
        printNodePRE(n);
    }
    else if( cmd=="IN" )
    {
        printNodeIN(n);
    }
    else
    {
        printNodePOST(n);
    }
    
}

int main()
{
    Queue* q = new Queue;
    Tree* t = new Tree;

    string commend = " ";
    string printOrder;
    string temp;
    string strnum;
    char cmdstr[15];
    char str[100];
    int number;

    while(1)
    {
        cout << "CMD>> ";
        //cin >> commend;
        cin.getline(str,15);
        //strcpy((char*)commend.c_str(), str);
        //strcpy(cmdstr, commend.c_str());
        strcpy(cmdstr, str);
        char *cmdptr = strtok(cmdstr, "\n ");
        if(cmdptr == NULL)
        {
            cout << "Error 100" << endl;
            continue;
        }
        else
        {
            commend = cmdptr;
        }   

        if(commend == "Print_Queue")
        {
            q->printQ();  
            cout << endl;                                
        }
        else if (commend == "EXIT")
        {
            return 0;
        }
        else if (commend == "PRINT")
        {
            //cin >> printOrder;
            cmdptr = strtok(NULL, " ");
            printOrder = cmdptr;
            if(printOrder == "PRE")             //전위
            {
                t->printNodeEmptyCheck(t->getRoot(),printOrder);
                cout << endl;         
            }
            else if(printOrder == "IN")         //중위
            {
                t->printNodeEmptyCheck(t->getRoot(),printOrder);
                cout << endl;
            }
            else if(printOrder == "POST")        //후위
            {
                t->printNodeEmptyCheck(t->getRoot(),printOrder);
                cout << endl;
            }
            else
            {
                cout << "Error 100" << endl;
            }
        }
        else if(commend == "Enqueue")
        {
            //char* ptr = strtok(NULL," ");
            cmdptr = strtok(NULL, " ");
            if(cmdptr == NULL)                                 //숫자가 입력이 되지 않은경우
            {
                cout <<"Error 200" << endl;
            }
            else
            {
                number = atoi(cmdptr);
                cmdptr = strtok(NULL, " ");

                if (cmdptr != NULL)                 // ptr이 NULL이 아니라면 숫자이후에 또 무언가가 입력됨
                {
                    cout << "Error 200" << endl;
                }
                else
                {
                    if (!number) //숫자가 아닌경우
                    {
                        cout << "Error 200" << endl;
                        //  cin.clear();
                        //  cin.ignore(5, '\n');
                    }
                    else
                    {
                        q->Enqueue(number);
                    }
                }
            }
        }
        else if(commend == "Dequeue")
        {

            cmdptr = strtok(NULL, " ");
            if (cmdptr == NULL) //숫자가 입력이 되지 않은경우
            {
                cout << "Error 200" << endl;
            }
            else
            {
                number = atoi(cmdptr);
                cmdptr = strtok(NULL, " ");

                if (cmdptr != NULL) // ptr이 NULL이 아니라면 숫자이후에 또 무언가가 입력됨
                {
                    cout << "Error 200" << endl;
                }
                else
                {
                    if (!number) //숫자가 아닌경우
                    {
                        cout << "Error 200" << endl;
                    }
                    else
                    {
                        q->Dequeue(number, t);
                    }
                }
            }      
            
        }
        else if(commend == "SEARCH")
        {
            cmdptr = strtok(NULL, " ");
            if (cmdptr == NULL) //숫자가 입력이 되지 않은경우
            {
                cout << "Error 200" << endl;
            }
            else
            {
                number = atoi(cmdptr);
                cmdptr = strtok(NULL, " ");

                if (cmdptr != NULL) // ptr이 NULL이 아니라면 숫자이후에 또 무언가가 입력됨
                {
                    cout << "Error 200" << endl;
                }
                else
                {
                    if (!number) //숫자가 아닌경우
                    {
                        cout << "Error 200" << endl;
                    }
                    else
                    {
                         t->searchNode(number);
                    }
                }
            }  
               
        }
        else
        {
            cout << "Error 100" << endl;
        }        
        
    }
    t->delTree(t->root);
    delete q;
    delete t;
}

//큐 - 삽입,삭제,출력
//트리 - 삽입,검색, 출력(pre,in,post)


//Example case1
