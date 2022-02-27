#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Node{
private:
    string s;
    Node* next;

public:
    Node(){next=NULL;}
    void setData(string word) {s=word;}
    void setNext(Node* node) {next=node;}
    string getData(){return s;}
    Node* getNext(){return next;}
};

class List{
private:
    Node *head;

public:
    List(){head=NULL;}
    ~List(){
        Node* currnode=head;
        Node* deletenode;
        while(currnode!=NULL){
            deletenode=currnode;
            currnode=currnode->getNext();
            delete deletenode;
        }
    };  //동적할당 해제하기
    bool isEmpty(){return head==NULL;}
    void set_head(string word){
        head=new Node; 
        head->setData(word);}
    void InsertNode(string word);
    string NodeWord();
    void print_Node();
    int find_Node(string word);
    int compare_Node(string word);
};

void List::InsertNode(string word)
{
    Node* curnode;
    curnode=head;
    while(curnode->getNext()!=NULL){
        curnode=curnode->getNext();
    }
    curnode->setNext(new Node);
    curnode=curnode->getNext();
    curnode->setData(word);
}

string List::NodeWord()
{
    Node *curnode;
    curnode=head;
    while(curnode->getNext()!=NULL){
        curnode=curnode->getNext();
    }
    return curnode->getData();
}

void List::print_Node()
{
    Node* currnode;
    currnode=head;
    while(currnode!=NULL){
        cout<<currnode->getData()<<"->";
        currnode=currnode->getNext();
    }
    cout<<"\n";
}

int List::find_Node(string word)
{
    Node* currtnode=head;
    while(currtnode!=NULL){
        if(word==currtnode->getData()){
            return 1;
            break;
        }
        currtnode=currtnode->getNext();
    }
    return 0;
}

int List::compare_Node(string word)
{
    char word_alpha=word.front();
    char re_alpha=NodeWord().back();
    if(word_alpha==re_alpha){
        return 1;
    }
    else{
        if(word_alpha>re_alpha){
            word_alpha-=32;
        }
        else if(word_alpha<re_alpha){
            re_alpha-=32;
        }

        if(word_alpha==re_alpha)
            return 1;
        else
            return 0;
    }
}

int main(){
    List list;
    while(1){
        string input;
        cout<<"CMD(Word/exit)>>";
        cin>>input;
        if(strcasecmp(input.c_str(), "exit")==0)  //exit 대문자/소문자 구별없이 인식하기 strcasecmp
            break;
        else{
            if(list.isEmpty()==true){  //첫번째 단어일때
                list.set_head(input);  //새로운 Node에 저장하기
                list.print_Node();  //썼던거 출력하기
            }
            else if(list.compare_Node(input)==1){
                //대문자 소문자 상관없이 동일할때
                if(list.find_Node(input)==0){  //if절 이미 썼던 단어이면 존재한다고 출력
                    list.InsertNode(input);  //Node에 삽입하기
                    list.print_Node();  //썼던거 출력하기
                }
                else{
                    cout<<"Already Exists\n";
                }
                
            }
            else
                cout<<"Not Chained\n";     
        }

    }
    return 0;
}