#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class treeNode{
private:
    int data;
    treeNode* right;
    treeNode* left;
    
public:
    treeNode(){data=0; right=NULL; left=NULL;}
    void SetData(int num){data=num;}
    void SetRight(treeNode* node){right=node;}
    void SetLeft(treeNode* node){left=node;}
    int GetData(){return data;}
    treeNode* GetRight(){return right;}
    treeNode* GetLeft(){return left;}
};

class Tree{
private:
    treeNode* head;
public:
    friend class Queue;
    Tree(){head=NULL;}
    ~Tree(){
        ClearNode(head);
    }  //동적할당 해제
    bool IsEmpty(){return head==NULL;}
    void SetHead(int data){
        head=new treeNode;
        head->SetData(data);
    }
    void ClearNode(treeNode* node);
    void InsertNode(int data);
    void PrintNode(string command);
    void PreOrder(treeNode* node); 
    void InOrder(treeNode* node);
    void PostOrder(treeNode* node);
    int SearchNode(int data);
};

class Node{
private:
    int x;
    Node* next;

public:
    Node(){x=0; next=NULL;}
    void SetData(int num){x=num;}
    void SetNext(Node* node){next=node;}
    int GetData(){return x;}
    Node* GetNext(){return next;}
};

class Queue{
    private:
        Node* front;
        Node* rear;

    public:
        Queue(){front=NULL; rear=NULL;}
        ~Queue(){
            Node* currnode=front;
            Node* delnode;
            while(currnode!=NULL){
                delnode=currnode;
                currnode=currnode->GetNext();
                delete delnode;
            }
        }  //동적할당 해제
        bool IsEmpty(){return front==NULL;}
        //bool IsNum(string s);
        void EnQueue(int num);
        void DeQueue(int num, Tree* tree);
        int CntQueue();
        int SameData(int num);
        void PrintQueue();
};



void Queue::EnQueue(int num)  //큐 추가하기
{
    if(IsEmpty()==true){  //front에 아무것도 없을때
        front=new Node;  //front 만들기
        front->SetData(num);
        rear=front;
    }
    else if(CntQueue()==5){  //큐가 다 차있을때
        cout<<"Error 300"<<endl;
    }
    else{
        if(SameData(num)==1){  //같은 값이 없을때
            Node* currnode=front;
            while(currnode->GetNext()!=NULL){
                currnode=currnode->GetNext();
            }
            currnode->SetNext(new Node);
            currnode=currnode->GetNext();
            currnode->SetData(num);
            rear=currnode;
        }
    }
}

void Queue::DeQueue(int num, Tree* tree)
{
    Node* currnode=front;
    Node* delnode;
    int cnt=CntQueue();
    if(cnt==0){  //큐가 비어있을때
        cout<<"Error 400"<<endl;
    }
    else if(num>cnt){  //입력한 값이 큐에 있는 것보다 클때
        while(currnode!=NULL){
            int data=currnode->GetData();
            tree->InsertNode(data);
            delnode=currnode;
            currnode=currnode->GetNext();
            delete delnode;
        }
        front=NULL; rear=NULL;
    }
    else{
        while(num){
            int data=currnode->GetData();
            tree->InsertNode(data);
            delnode=currnode;
            currnode=currnode->GetNext();
            front=currnode;
            delete delnode;
            num--;
        }
    }
}

int Queue::CntQueue()
{
    Node* currnode=front;
    int cnt=0;
    if(IsEmpty()==true)  //front가 비어있을때
        return cnt;
    else{  //front가 있을때
        cnt+=1;
        while(currnode->GetNext()!=NULL){
            currnode=currnode->GetNext();
            cnt+=1;
        }
        return cnt;
    }
}

int Queue::SameData(int num)  //같은 값이 있으면 0, 없으면 1
{
    Node* currnode=front;
    while(currnode!=NULL){
        if(currnode->GetData()==num)
            return 0;
        else
            currnode=currnode->GetNext();
    }
    return 1;
}

void Queue::PrintQueue()
{
    Node* currnode=front;
    if(CntQueue()==0){
        cout<<"Error 500"<<endl;
    }
    else{
        while(currnode!=NULL){
            cout<<currnode->GetData()<<" ";
            currnode=currnode->GetNext();
        }
        cout<<endl;
    }
}



void Tree::ClearNode(treeNode* node)
{
    if(node!=NULL){
        ClearNode(node->GetLeft());
        delete node;
        ClearNode(node->GetRight());
    }
}

void Tree::InsertNode(int data)
{
    if(IsEmpty()==true){  //head가 비어있을때
        SetHead(data);  //head를 만든다
    }
    else{
        treeNode* currnode=head;
        while(currnode!=NULL){
            if(currnode->GetData()>data){
                if(currnode->GetLeft()==NULL){
                    currnode->SetLeft(new treeNode);
                    currnode=currnode->GetLeft();
                    currnode->SetData(data);
                    break;
                }
                else{
                    currnode=currnode->GetLeft();
                }
            }
            else if(currnode->GetData()<data){
                if(currnode->GetRight()==NULL){
                    currnode->SetRight(new treeNode);
                    currnode=currnode->GetRight();
                    currnode->SetData(data);
                    break;
                }
                else{
                    currnode=currnode->GetRight();
                }
            }
            else if(currnode->GetData()==data)
                break;
        }
    }
}

void Tree::PrintNode(string command)
{
    if(command=="PRE"){
        PreOrder(head);
    }
    else if(command=="IN"){
        InOrder(head);
    }
    else if(command=="POST"){
        PostOrder(head);
    }
}

void Tree::PreOrder(treeNode* node)
{
    if(node!=NULL){
        cout<<node->GetData()<<" ";
        PreOrder(node->GetLeft());
        PreOrder(node->GetRight());
    }
}

void Tree::InOrder(treeNode* node)
{
    if(node!=NULL){
        InOrder(node->GetLeft());
        cout<<node->GetData()<<" ";
        InOrder(node->GetRight());
    }
}

void Tree::PostOrder(treeNode* node)
{
    if(node!=NULL){
        PostOrder(node->GetLeft());
        PostOrder(node->GetRight());
        cout<<node->GetData()<<" ";
    }
}

int Tree::SearchNode(int data)
{
    treeNode* currnode=head;
    while(currnode!=NULL){
        if(currnode->GetData()>data){
            currnode=currnode->GetLeft();
        }
        else if(currnode->GetData()<data){
            currnode=currnode->GetRight();
        }
        else if(currnode->GetData()==data){
            return 1;
        }
    }
    return 0;
}

int main()
{
    Tree* tree = new Tree;
    Queue* queue = new Queue;
    string str;
    string commend;
    char ch[30];
    while (1) {
        cout << "CMD>> ";
        getline(cin, str);
        strcpy(ch, str.c_str());
        char* temp = strtok(ch, " ");

        if (temp == NULL)
            cout << "Error 100"<<endl;
        else {
            commend = temp;

            if (commend == "Enqueue") {
                temp = strtok(NULL, " ");
                if (temp == NULL)
                    cout << "Error 200" << endl;
                else {
                    if (strtok(NULL, " ") != NULL)
                        cout << "Error 200" << endl;
                    else {
                        int num = atoi(temp);
                        if (num==0&&isdigit(*temp)==0)  //문자일때
                            cout << "Error 200" << endl; 
                        else
                            queue->EnQueue(num);
                    }
                }
            }

            else if (commend == "Dequeue") {
                temp = strtok(NULL, " ");
                if (temp == NULL)
                    cout << "Error 200" << endl;
                else {
                    if (strtok(NULL, " ") != NULL)
                        cout << "Error 200" << endl;
                    else {
                        int num = atoi(temp);
                        if (num == 0 && isdigit(*temp) == 0)  //문자일때
                            cout << "Error 200" << endl;
                        else
                            queue->DeQueue(num, tree);
                    }
                }
                
            }

            else if (commend == "Print_Queue") {
                queue->PrintQueue();

            }

            else if (commend == "SEARCH") {
                temp = strtok(NULL, " ");
                if (temp == NULL)  //값이 비어있을때
                    cout << "Error 200" << endl;
                else {
                    if (strtok(NULL, " ") != NULL)  //두개 이상의 값이 입력되었을때
                        cout << "Error 200" << endl;
                    else {
                        int data = atoi(temp);
                        if (data == 0 && isdigit(*temp) == 0)  //문자일때
                            cout << "Error 200" << endl;
                        else {
                            if (tree->SearchNode(data) == 1)
                                cout << data << "is exists" << endl;
                            else
                                cout << "Error 600" << endl;
                        }
                    }
                }
            }

            else if (commend == "PRINT") {
                 temp = strtok(NULL, " ");
                if (temp == NULL)  //뒷 인자가 공백일때
                    cout << "Error 200" << endl;
                else {
                    if (strtok(NULL, " ") != NULL)  //뒷 인자가 두개 이상일때
                        cout << "Error 200" << endl;
                    else {
                        if (atoi(temp) == 0 && isdigit(*temp) == 0) {  //인자가 문자일때
                            string s = temp;
                            if (s == "PRE" || s == "IN" || s == "POST") {
                                if (tree->IsEmpty() == true)
                                    cout << "Error 700" << endl;
                                else {
                                    tree->PrintNode(s);
                                    cout << endl;
                                }
                            }
                            else
                                cout << "Error 200" << endl;
                        }
                        else
                            cout << "Error 200"<<endl;
                    }
                }
                
            }

            else if (commend == "EXIT") {
                break;
            }

            else {
                cout << "Error 100" << endl;
            }
        }
    }
    delete queue;
    return 0;
}