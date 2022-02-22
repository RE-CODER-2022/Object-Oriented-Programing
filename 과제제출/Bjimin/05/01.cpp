#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Tree;

class Node{
private:
    int value;
    Node* next;

    Node* left;
    Node* right;

public:
    Node(){ next = left = right = NULL; }
    void SetValue(int snum){ this->value = snum;}
    int GetValue(){ return this->value;}
    void SetNext(Node* snode){ next = snode;}
    Node* GetNext(){ return next; }
    void SetLeft(Node* snode){ left = snode;}
    Node* GetLeft(){ return left; }
    void SetRight(Node* snode){ right = snode;}
    Node* GetRight(){ return right; }
};

class Queue{
private:
    Node* front;
    Node* rear;
    int counter;
public:
    Queue(){
        front = rear = NULL;
        counter = 0;    
    }
    ~Queue(){                       //노드 할당 해제
        Node * delnode;
        if(!IsEmpty()){
            while(front){
                delnode = front;
                front = delnode->GetNext();
                delete delnode;
            }
        }
    }

    bool IsEmpty(){
        return counter==0;
    }

    bool Enqueue(int num);
    bool Dequeue(int num, Tree * tree);
    bool DisplayQueue();
};

bool Queue::Enqueue(int num){
    Node* newnode = new Node;
    newnode->SetValue(num);
    newnode->SetNext(NULL);
    if(counter>=5)
        return false;
    if(IsEmpty()){ //비었을때
        front = rear = newnode;
    }
    else{
        rear->SetNext(newnode);
        rear = rear->GetNext();
    }
    counter++;
    return true;
}


bool Queue::DisplayQueue(){
    Node * curnode;
    if(counter==0)
        return false;
    else{
        curnode = front;
        while(curnode){
            cout<<curnode->GetValue()<<"\t";
            curnode = curnode->GetNext();
        }
        cout<<endl;
    }
    return true;
}

class Tree{
private:
    Node * rootnode;
public:
    Tree(){rootnode = NULL;}
    ~Tree(){                        //노드 할당 해제
        Node * pointer = rootnode;
        if(pointer){
            MoveTree(pointer->GetLeft());
            MoveTree(pointer->GetRight());
            delete pointer;
        }
    }
    Node * GetRootnode(){return rootnode;}

    Node * Search(int num, Node * pointer);
    bool DisplayTree(string command);
    void InsertTree(int num, Node * curnode);
    void PreOrder(Node * pointer);
    void InOrder(Node * pointer);
    void PostOrder(Node * pointer);
    void MoveTree(Node * pointer);
};

Node * Tree::Search(int num, Node * pointer){ //rootnode부터 시작해서 값 찾는 함수
    if(pointer == NULL)
        return NULL;
    if(pointer->GetValue() == num)
        return pointer;
    else if(pointer->GetValue() > num){
        return Search(num, pointer->GetLeft());
    }
    else{
        return Search(num, pointer->GetRight());
    }
}

void Tree::MoveTree(Node * pointer){
    if(pointer){
        MoveTree(pointer->GetLeft());
        MoveTree(pointer->GetRight());
        delete pointer;
    }
}

void Tree::PreOrder(Node * pointer){
    if(pointer){
        cout<<pointer->GetValue()<<"\t";
        PreOrder(pointer->GetLeft());
        PreOrder(pointer->GetRight());
    }
}

void Tree::InOrder(Node * pointer){
    if(pointer){
        InOrder(pointer->GetLeft());
        cout<<pointer->GetValue()<<"\t";
        InOrder(pointer->GetRight());
    }
}

void Tree::PostOrder(Node * pointer){
    if(pointer){
        PostOrder(pointer->GetLeft());
        PostOrder(pointer->GetRight());
        cout<<pointer->GetValue()<<"\t";
    }
}

bool Tree::DisplayTree(string command){
    if(rootnode == NULL) 
        return false;
    if(command == "PRE"){
        PreOrder(rootnode);
    }
    else if(command == "IN"){
        InOrder(rootnode);
    }
    else if(command == "POST"){
        PostOrder(rootnode);
    }
    else{
        cout<<"Error 200"<<endl;
        return true;
    }
    cout<<endl;
    return true;
}

void Tree::InsertTree(int num, Node * curnode){ //rootnode부터 시작해서 올바른 위치에 노드 생성
    Node * newnode = new Node;
    newnode->SetValue(num);
    newnode->SetLeft(NULL);
    newnode->SetRight(NULL);

    if(rootnode == NULL)
        rootnode = newnode;
    else if(curnode->GetValue()>num)
        if(curnode->GetLeft() == NULL)
            curnode->SetLeft(newnode);
        else
            InsertTree(num, curnode->GetLeft());

    else if(curnode->GetValue()<num)
        if(curnode->GetRight() == NULL)
            curnode->SetRight(newnode);
        else
            InsertTree(num, curnode->GetRight());
        


}

bool Queue::Dequeue(int num, Tree * tree){
    Node * delnode;
    if(IsEmpty())
        return false;
    else{
        while(front && num){
            delnode = front;
            front = delnode->GetNext();
            tree->InsertTree(delnode->GetValue(),tree->GetRootnode());
            delete delnode;
            num--;
            counter--;
        }
    }
    return true;
}

int Countspacebar(string command){
    int sum=0;
    for(int i=0; command[i]!='\0'; i++){
        if(command[i]==' '){
            sum++;
        }
    }
    return sum;
}


int main(){
    string command_all;
    char arr[100];
    string command;
    Queue * queue = new Queue;
    Tree * tree = new Tree;
    int spacebar;
    int num;
    while(true){
        cout<<"CMD>> ";
        getline(cin,command_all);
        spacebar = Countspacebar(command_all);
        if(spacebar==0)
            command = command_all;
        else{
            strncpy(arr,command_all.c_str(),sizeof(arr));
            command = strtok(arr, " ");
        }

        if(command == "Enqueue"){
            if(spacebar==1){
                command = strtok(NULL, " ");
                num = atoi(command.c_str());
                if(num!=0){
                    if(!queue->Enqueue(num))
                        cout<<"Error 300"<<endl;
                }
                else{
                    cout<<"Error 200"<<endl;
                }
            }
            else{
                cout<<"Error 200"<<endl;
            }
        }
        else if(command == "Dequeue"){
            if(spacebar==1){
                command = strtok(NULL, " ");
                num = atoi(command.c_str());
                if(num!=0){
                    if(!queue->Dequeue(num,tree))
                        cout<<"Error 400"<<endl;
                }
                else{
                    cout<<"Error 200"<<endl;
                }
            }
            else{
                cout<<"Error 200"<<endl;
            }
        }
        else if(command == "Print_Queue"){
            if(spacebar==0){
                if(!queue->DisplayQueue())
                    cout<<"Error 500"<<endl;
            }
            else{
                cout<<"Error 200"<<endl;
            }
        }
        else if(command == "SEARCH"){
            if(spacebar==1){
                command = strtok(NULL, " ");
                num = atoi(command.c_str());
                if(num!=0){
                    if(tree->Search(num,tree->GetRootnode())==NULL)
                        cout<<"Error 600"<<endl;
                    else
                        cout<<num<<"is exists"<<endl;
                }
                else{
                    cout<<"Error 200"<<endl;
                }
            }
            else{
                cout<<"Error 200"<<endl;
            }
        }
        else if(command == "PRINT"){
            if(spacebar==1){
                command=strtok(NULL," ");
                if(!tree->DisplayTree(command))
                    cout<<"Error 700"<<endl;
            }
            else{
                cout<<"Error 200"<<endl;
            }
            
        }
        else if(command == "EXIT"){
            if(spacebar==0)
                break;
            else
                cout<<"Error 200"<<endl;
        }
        else{
            cout<<"Error 100"<<endl;
        }
    }
    delete queue;
    delete tree;
}