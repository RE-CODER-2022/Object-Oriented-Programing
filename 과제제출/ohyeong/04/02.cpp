#include <iostream>
#include <random>

using namespace std;

class Node{
private:
    int bullet;
    Node* next;

public:
    Node(){bullet=0; next=NULL;}
    void setBullet(int x){bullet=x;}
    void setNext(Node* node) {next=node;}
    int getBullet(){return bullet;}
    Node* getNext(){return next;} 
};

class List{
private:
    Node* head;

public:
    List(){head=NULL;}
    ~List(){
        Node* curnode=head;
        Node* deletenode;
        for(int i=0;i<6;i++){
            deletenode=curnode;
            curnode=curnode->getNext();
            delete deletenode;
        }
    }
    void set_head(){
        head=new Node;
        head->setBullet(1);}
    void make_Node();
    void rotate_Node();
    int dis_Bullet();
    void next_Node(){head=head->getNext();}
};

void List::make_Node()
{
    set_head();
    Node* currnode=head;
    for(int i=0;i<5;i++){
        currnode->setNext(new Node);
        currnode=currnode->getNext();
    }
    currnode->setNext(head);
    rotate_Node();
}

void List::rotate_Node()
{
    int a;
    random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);
    a = dis(gen);
    for(int i=0;i<a;i++){
        head=head->getNext();
    }
}

int List::dis_Bullet(){
    if(head->getBullet()==1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    List list;
    list.make_Node();
    string input;
    cout<<"Command list(shoot/rotate)\n";
    while(1){
        cout<<"CMD>> ";
        cin>>input;
        if(input=="shoot"){
            if(list.dis_Bullet()==1){
                cout<<"You Died...\n";
                break;
            }
            else if(list.dis_Bullet()==0){
                cout<<"Youd Survived!\n";
                list.next_Node();
            }
        }
        else if(input=="rotate"){
            list.rotate_Node();
            system("clear");
        }
        else{
            cout<<"Wrong Command!\n";
        }
    }
    return 0;
}