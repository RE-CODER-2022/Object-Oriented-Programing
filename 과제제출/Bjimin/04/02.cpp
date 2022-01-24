#include<iostream>
#include <stdlib.h>
#include<random>
using namespace std;

class Node{
private:
    bool bullet;
    Node * next;
    Node * prev;

public:
    Node(){}
    ~Node(){}

    void set_bullet(bool torf){ bullet = torf; }
    bool get_bullet(){ return bullet; }
    
    void set_next(Node * nextnode){ next = nextnode; }
    Node * get_next(){ return next; }

    void set_prev(Node * prevnode){ prev = prevnode; }
    Node * get_prev(){ return prev; }
};

class Revolver{
private:
    Node * head;

public:
    Revolver(){                                     //생성자에서 노드 6개 생성
        head=NULL;
        Node * curnode;
        for(int i=0; i<6; i++){
            Node * newnode = new Node;
            if(head==NULL){
                head = newnode;
                curnode = head;
                head->set_bullet(true);
                head->set_next(NULL);
                head->set_prev(NULL);
                
            }
            else{
                newnode->set_prev(curnode);
                curnode->set_next(newnode);
                curnode = curnode->get_next();
                curnode->set_bullet(false);
                curnode->set_next(NULL);
            }
        }
        curnode->set_next(head);
        head->set_prev(curnode);
        rotate();                              //총알의 위치 바꾸기 위해 한번 돌리기

    }
    ~Revolver(){                                //노드들 할당 해제
        Node * curnode = head->get_next();
        Node * delnode;
        while(curnode != head){
            delnode = curnode;
            curnode = curnode->get_next();
            delete delnode;
        }
        delete head;
    }

    void rotate(){                  //head의 위치를 랜덤으로 이동시켜 총알의 위치 바꾸기
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0,6);
        int headlocation = dis(gen);
        while(headlocation--){
            head = head->get_next();
        }

    }

    void shootrevolver(){                       //총 발사, head옮기고 그전head 없애고 다시 연결
        Node * curnode = head;
        head = head->get_next();
    }

    bool bulletornot(){
        return head->get_bullet();
    }


    // void prin(){
    //     Node * curnode = head->get_next();
    //     Node * delnode;
    //     cout<<head->get_bullet()<<endl;
    //     while(curnode != head){
    //         cout<<curnode->get_bullet()<<endl;
    //         curnode = curnode->get_next();
    //     }
    // }
    //- 잘 실행되는지 테스트한 코드
};


int main(){
    Revolver * revolver = new Revolver;
    string command;
    cout<<"Command list(shoot/rotate)"<<endl;
    while(true){
        cout<<"CMD>> ";
        cin>>command;
        if(command == "shoot"){
            if(revolver->bulletornot()){ //만약 총알이 있으면
                cout<<"You Died..."<<endl;

                break;
            }
            else{
                cout<<"You Survived!"<<endl;

                revolver->shootrevolver();
                //없어진 노드 개수만큼 rotate에 영향
            }
        }

        else if(command == "rotate"){
            revolver->rotate();
            system("clear"); //리눅스나 bash에서는 cls가 안된다고 해서 변경
        }

        else
            cout<<"Wrong Command!"<<endl;

        }

    delete revolver;
}