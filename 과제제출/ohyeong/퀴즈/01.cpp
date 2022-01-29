#include <iostream>
#include <string>

using namespace std;

class Node{
private:
    string s;
    Node* next;
    Node* prev;

public:
    Node(){next=NULL; prev=NULL;}
    void SetNext(Node* node){next=node;}
    void SetWord(string word){s=word;}
    void SetPrev(Node* node){prev=node;}
    Node* GetNext(){return next;}
    string GetWord(){return s;}
    Node* GetPrev(){return prev;}
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
        }
    }//동적할당 해제
    bool ExistHead(){return head==NULL;}
    void SetHead(string word){  //head만들기
        head=new Node;
        head->SetWord(word);}  
    void CompareNode(string word);
    void InsertHead(string word, Node* currnode);
    void InsertNode(string word, Node* currnode);
    void AddNode(string word, Node* currnode);
    int SameNode(string word);
    void PrintNode();
    int FindNode(string word);
    int DeleteNode(string word);
};

void List::CompareNode(string word)
{
   Node* currnode=head;
   while(currnode!=NULL)
   {
       if(currnode->GetWord()>word){  //입력한게 작을때
           if(currnode->GetPrev()==NULL){  //그전 노드가 없을때
               InsertHead(word, currnode);
               break;
           }
           else{
               InsertNode(word, currnode);
               break;
           }
       }

       else{  //입력한게 뒤에 갈때
           if(currnode->GetNext()==NULL){
               AddNode(word, currnode);
               break;
           }
           else{
               currnode=currnode->GetNext();
           }
       }
   }
}


void List::InsertHead(string word, Node* currnode)  //head앞에 노드넣을떄
{
    Node* newnode=new Node;
    newnode->SetWord(word);
    newnode->SetNext(currnode);
    currnode->SetPrev(newnode);
    head=newnode;
}

void List::InsertNode(string word, Node* currnode)  //노드사이에 노드넣을때
{
    Node* newnode=new Node;
    newnode->SetWord(word);
    newnode->SetNext(currnode);
    newnode->SetPrev(currnode->GetPrev());
    currnode->GetPrev()->SetNext(newnode);
    currnode->SetPrev(newnode);
}

void List::AddNode(string word, Node* currnode)  //맨뒤에 노드를 추가할때
{
    Node* newnode=new Node;
    newnode->SetWord(word);
    newnode->SetPrev(currnode);
    currnode->SetNext(newnode);
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
    for(int i=0;currnode!=NULL;i++){
        cout<<i<<". "<<currnode->GetWord()<<endl;
        currnode=currnode->GetNext();
    }
}

int List::FindNode(string word)
{
    int cnt=0;
    Node* currnode=head;
    while(currnode!=NULL){
        if(currnode->GetWord()==word){
            cout<<cnt<<". "<<word<<endl;
            return 1;
        }
        currnode=currnode->GetNext();
        cnt+=1;
    }
    return 0;
}

int List::DeleteNode(string word)  //없으면 0, 있으면 1
{
    Node* currnode=head;
    while(currnode!=NULL){
        if(currnode->GetWord()==word){
            if(currnode->GetPrev()==NULL){  //앞에 노드가 없을때(head일떄)
                head=currnode->GetNext();
                delete currnode;
                return 1;
            }
            else if(currnode->GetNext()==NULL){  //뒤에 노드가 없을때
                currnode->GetPrev()->SetNext(NULL);
                delete currnode;
                return 1;
            }
            else{
                currnode->GetNext()->SetPrev(currnode->GetPrev());
                currnode->GetPrev()->SetNext(currnode->GetNext());
                delete currnode;
                return 1;
            }
           
        }
        currnode=currnode->GetNext();
    }
    return 0;
}

int main()
{
    List list;
    string command,word;
    while(1){
        cin>>command;
        if(command=="INSERT"){
            cin>>word;
            if(list.ExistHead()==true){  //head가 존재하지 않으면
                list.SetHead(word);
                list.PrintNode();
            }
            else{  //head가 존재할때
                if(list.SameNode(word)==0){  //서로 같으면 1 다르면 0
                    list.CompareNode(word);
                    list.PrintNode();
                }
                else
                    list.PrintNode();
            }
            
        }
        else if(command=="FIND"){
            cin>>word;
            if(list.FindNode(word)==0){
                cout<<"Not Found"<<endl;
            }
        }
        else if(command=="DELETE"){
            cin>>word;
            if(list.DeleteNode(word)==0){  //없으면 0 있으면 1
                cout<<"Not Found"<<endl;
            }
            else
                list.PrintNode();
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
