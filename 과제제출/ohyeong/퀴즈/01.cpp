#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Node{
private:
    string s;
    int num;
    Node* next;

public:
    void SetNext(Node* node){next=node;}
    void SetWord(string word){s=word;}
    void SetNum(int number){num=number;}
    Node* GetNext(){return next;}
    string GetWord(){return s;}
    int GetNum(){return num;}
};

class List{
private:
    Node* head;

public:
    List(){head=NULL;}
    ~List(){
        Node* currnode=head;
        Node* delenode;
        while(currnode!=NULL){
            delenode=currnode;
            currnode=currnode->GetNext();
            delete delenode;
        }//동적할당 해제
    }
    bool ExistHead(){return head==NULL;}
    void SetHead(string word){
        head=new Node;
        head->SetNum(0);
        head->SetWord(word);}
    void CompareNode(string word);
    int SameNode(string word);
    void PrintNode();
    
};

void List::CompareNode(string word)
{
    Node* currnode=head;
    while(currnode!=NULL){  //비어있을때까지 반복
        if(currnode->GetWord().front()>word.front()){  //앞글자가 입력받은거보다 클때
            if(currnode==head){  //지금 노드가 head일때
                Node* newnode=new Node;
                newnode->SetWord(word);
                newnode->SetNum(0);
                newnode->SetNext(currnode->GetNext());
                head=newnode;
                while(currnode!=NULL){
                    currnode->SetNum(currnode->GetNum()+1);
                    currnode=currnode->GetNext();
                }
                break;
            }
            else{
                Node* newnode= new Node;
                newnode->SetWord(word);
                newnode->SetNum(currnode->GetNum()+1);
                newnode->SetNext(currnode->GetNext());
                currnode->SetNext(newnode);
                while(currnode!=NULL){
                    currnode->SetNum(currnode->GetNum()+1);
                    currnode=currnode->GetNext();
                }
                break;
            }
        }
        else if(currnode->GetWord().front()==word.front()){
            if(currnode->GetWord().size()<word.size()){
                Node* newnode= new Node;
                newnode->SetWord(word);
                newnode->SetNum(currnode->GetNum()+1);
                newnode->SetNext(currnode->GetNext());
                currnode->SetNext(newnode);
                break;
            }
            else{
                currnode=currnode->GetNext();
            }
        }
        else{
            if(currnode->GetNext()==NULL){
                Node* newnode= new Node;
                newnode->SetWord(word);
                newnode->SetNum(currnode->GetNum()+1);
                currnode->SetNext(newnode);
                break;
            }
            else
                currnode=currnode->GetNext();
        }
    }
}

int List::SameNode(string word)  //서로 같으면 1 다르면 0
{
    Node* currnode=head;
    while(currnode!=NULL){
        if(currnode->GetWord()==word){
            return 1;
        }
        else{
            currnode=currnode->GetNext();
        }
    }
    return 0;
}

void List::PrintNode()
{
    Node* currnode=head;
    while(currnode!=NULL){
        cout<<currnode->GetNum()<<". "<<currnode->GetWord()<<endl;
        currnode=currnode->GetNext();
    }
}

int main()
{
    List list;
    string command,word;
    while(1){
        cin>>command;
        
        if(command=="INSERT"){
            cin>>word;
            if(list.ExistHead()==true){
                list.SetHead(word);
                list.PrintNode();
            }
            else{
                if(list.SameNode(word)==0){
                    list.CompareNode(word);
                    list.PrintNode();
                }
                else
                    continue;
            }
            
        }
        else if(command=="FIND"){
            cin>>word;
            break;
        }
        else if(command=="DELETE"){
            cin>>word;
            break;
        }
        else if(command=="END"){
            break;
        }
        else{
            continue;
        }
    }

    return 0;
}
