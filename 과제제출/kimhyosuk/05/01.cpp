#include<iostream>
#include<cstring>
using namespace std;
#define MaxValue 6
int a = 0;

class Node{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int num)
        {
            this->data = num;
            left = NULL;
            right = NULL;
        }
        int GetData(){return data;}
        Node* GetLeft(){return left;}
        Node* GetRight(){return right;}
        void SetLeft(Node* _data){this->left=_data;}
        void SetRight(Node* _data){this->right=_data;}
};
class Tree{
    private:
        Node* root;
    public:
        Node* GetRoot(){return root;}
        Node* _SearchTree(Node* tree,int _data);
        void InsertTree(int _data);
        void PrintTreePre(Node* n);
        void PrintTreeIn(Node* n);
        void PrintTreePost(Node* n);
        Tree() : root(NULL){}
};
class Queue{
    private:
        int front;
        int rear;
        int size;
        int* value;
        int count;
    public:
        Queue()
        {
            size = MaxValue;
            value = new int[size];
            front = 0;//처음 index를 가르키다가 pop되면 다음 index 가르킴
            rear = 0;//queue에 push된 index 가르키는 용도 queue의 마지막index
            count = 0;//queue크기 세는 용도
        }
        ~Queue()
        {
            delete[] value;
        }
        bool isFull()
        {
            if((rear+1)%size == front)
                return true;
            else
                return false;
        }
        void Enqueue(int num)
        {
            if(isFull() != true)
            {
                value[rear] = num;
                rear = (rear + 1) %size;
                count++;
            }
            else
                cout<<"Error 300"<<endl;
        }
        void Dequeue(int num, Tree* T)
        {
            Node* _data = T->GetRoot();
            int data;
            if(count < num)
                num = count;
            if(num >= 0)
            {
                if(num == 0)
                {
                    cout<<"Error 400"<<endl;
                }
                else
                {
                    for(int i =0;i<num;i++)
                    {
                        if(count > 0)
                        {
                            data = value[front%size];
                            T->InsertTree(data);
                            front = (front+1) %size;
                            count--;
                        }
                    }
                }
            }
        }
        void PrintQueue()
        {
            int index = 0;
            index = front%size;
            while(1)
            {
                if(count == 0)
                {
                    cout<< "Error 500";
                    break;
                }
                else if((index+1)%size != rear)
                {
                    cout<<value[index%size]<<"  ";
                    index++;
                }
                else if((index+1)%size == rear)
                {
                    cout<<value[index%size]<<"  ";
                    break;
                }
            }
        }
};
Node* Tree::_SearchTree(Node* tree,int target)
{
    if(tree == NULL)
        return NULL;
    if(tree->GetData() == target)
        return tree;
    else if(tree->GetData() > target)
        return _SearchTree(tree->GetLeft(),target);
    else if(tree->GetData() < target)
        return _SearchTree(tree->GetRight(),target);
    return NULL;
}
void Tree::InsertTree(int _data)
{
    Node* Newnode = new Node(_data);
    Node* tmpRoot = NULL;
    if(!root)
        root = Newnode;
    else{
        Node* ptr = root;
        while(ptr != NULL)
        {
            tmpRoot = ptr;
            if(Newnode->GetData() < ptr->GetData())
                ptr = ptr->GetLeft();
            else if(Newnode->GetData() > ptr->GetData())
                ptr = ptr->GetRight();
            else
                return;
        }
        if(Newnode->GetData() > tmpRoot->GetData())
            tmpRoot->SetRight(Newnode);
        else
            tmpRoot->SetLeft(Newnode);
    }
}
void Tree::PrintTreePre(Node* tree)//전위 순회
{
    if(!tree)
    {
        cout<<"Error 700";
        return;
    }
    cout<<tree->GetData()<<" ";
    if(tree->GetLeft())
        PrintTreePre(tree->GetLeft());
    if(tree->GetRight())
        PrintTreePre(tree->GetRight());
}
void Tree::PrintTreeIn(Node* tree)//중위 순회
{
    if(!tree)
    {
        cout<<"Error 700";
        return;
    }
    if(tree->GetLeft())
        PrintTreeIn(tree->GetLeft());
    cout<<tree->GetData()<<" ";
    if(tree->GetRight())
        PrintTreeIn(tree->GetRight());
}
void Tree::PrintTreePost(Node* tree)//후위순회
{
    if(!tree)
    {
        cout<<"Error 700";
        return;
    }
    if(tree->GetLeft())
        PrintTreePost(tree->GetLeft());
    if(tree->GetRight())
        PrintTreePost(tree->GetRight());
    cout<<tree->GetData()<<" ";
}
int main()
{
    Queue* q = new Queue;
    Tree* t = new Tree;
    string _input;
    string _input1;
    char input[50] = {'\0'};
    char input1[50] = {'\0'};
    while(1)
    {
        cout<<"CMD>> ";
        cin>>input;
        _input = input;
        if(_input.compare("Print_Queue") == 0)
        {
            q->PrintQueue();
            cout<<endl;
            cin.clear();
            continue;
        }
        else if(_input.compare("EXIT") == 0)
        {
            return 0;
        }
        cin>>input1;
        if(_input.compare("Enqueue") == 0)
        {
            a = atoi(input1);
            q->Enqueue(a);
        }
        else if(_input.compare("Dequeue") == 0)
        {
            a = atoi(input1);
            q->Dequeue(a,t);
        }
        else if(_input.compare("SEARCH") == 0)
        {
            a = atoi(input1);
            if(input1 == NULL)
                cout<<"Error 200"<<endl;
            else{
                a = atoi(input1);
                if(!input1)
                    cout<<"Error 600"<<endl;
                else{
                    if(a)
                        cout<<"Error 600"<<endl;
                    else
                    {
                        if(t->_SearchTree(t->GetRoot(),a) != NULL)
                        {
                            cout<<a<<"is exists"<<endl;
                        }
                    }
                }
            }
        }
        else if(_input.compare("PRINT") == 0)
        {
            _input1 = input1;
            if(_input1.compare("PRE") == 0)
            {
                t->PrintTreePre(t->GetRoot());
                cout<<endl;
            }
            else if(_input1.compare("IN") == 0)
            {
                t->PrintTreeIn(t->GetRoot());
                cout<<endl;
            }
            else if(_input1.compare("POST") == 0)
            {
                t->PrintTreePost(t->GetRoot());
                cout<<endl;
            }
            else
                cout<<"Error 100"<<endl;
        }
        else
            cout<<"Error 100"<<endl;
        cin.ignore();
    }
    delete q;
    delete t;
    return 0;
}