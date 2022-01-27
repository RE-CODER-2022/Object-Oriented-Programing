#include<iostream>
#include<cstring>
using namespace std;

class Node{
private:
    string word;

public:
    Node* next;
    Node(){}
    ~Node(){}

    string getword(){ return word; }
    void setword(string word){ this->word = word; }
};

class List{
private:
    Node* head;

public:
    List(){ head = NULL; }
    ~List(){
        Node* curnode = head;
        Node* delnode;

        while(curnode!= NULL){
            delnode = curnode;
            curnode = curnode->next;

            delete delnode;
        }
    }

    void InsertNode(string wordin){
        Node* curnode = head;
        Node* prvnode = NULL;

        Node* newnode = new Node;
        

        if(head==NULL){ //노드가 생성되는 곳이 첫 번째일 경우(아직 아무것도 없을 때)
            head = newnode;
            newnode->next = NULL;
            newnode->setword(wordin);            
        }

        else{
            while(curnode != NULL){
                if(strcmp(curnode->getword().c_str(), wordin.c_str())<0){//word<wordin이면 음수, 같으면 0, word>wordin이면 양수 반환됨
                    prvnode = curnode;
                    curnode = curnode->next;
                }
                else{
                    break;
                } //빠져나왔을 경우엔, 지금 curnode보다 사전순으로 앞에 있는 경우 또는 같을 경우
            }
            if(curnode == head){ //처음에 넣어야 하는 경우
                head = newnode;
                newnode->next = curnode;
                newnode->setword(wordin);
            }
            else if(curnode==NULL || strcmp(curnode->getword().c_str(), wordin.c_str())>0){
                    if(curnode==NULL){//마지막노드일 경우
                        prvnode->next = newnode;
                        newnode->next = NULL;
                        newnode->setword(wordin);
                    }
                    else{
                        if(prvnode!=NULL)
                            prvnode->next = newnode;
                        newnode->next = curnode;
                        newnode->setword(wordin);
                    }


                }
            else if(strcmp(curnode->getword().c_str(), wordin.c_str())==0)//중복일 경우 아무것도 안함.
                delete newnode;


        }




        int indx = 0; //전체출력
        curnode = head;
        while(curnode){
            cout<<indx<<". "<<curnode->getword()<<endl;
            curnode = curnode->next;
            indx++;
        }
        
    }

    void FindeNode(string wordf){
        Node* curnode = head;
        int index = 0;
        while(curnode!=NULL){
            if(curnode->getword() == wordf)
                break;
            else{
                curnode = curnode->next;
                index++;
                }
        }

        if(curnode!=NULL){
            cout<<index<<". "<<wordf<<endl;
        }
        else{
            cout<<"Not found"<<endl;
        }
    }

    void DeleteNode(string wordd){
        Node* curnode = head;
        Node* delnode;
        Node* prvnode = NULL;
        while(curnode->getword() != wordd){

            prvnode = curnode;
            curnode = curnode->next;
        }

        if(curnode!=NULL){ //아무것도 없지 않을 때
            delnode = curnode;
            curnode = curnode->next;

            //지우는게 head면
            if(prvnode == NULL){
                head = curnode;
            }
            else{ //아니면
                prvnode->next = curnode;
            }

            delete delnode;
        }


        int indx = 0;
        curnode = head;
        while(curnode){
            cout<<indx<<". "<<curnode->getword()<<endl;
            curnode = curnode->next;
            indx++;
        }

    }


};


int main(){
    string command;
    string word;

    List * list = new List;
    while(true){
        cin>>command;
        if(command=="INSERT"){
            cin>>word;
            list->InsertNode(word);
        }
        else if(command=="FIND"){
            cin>>word;
            list->FindeNode(word);
        }
        else if(command=="DELETE"){
            cin>>word;
            list->DeleteNode(word);
        }
        else if(command=="END"){
            break;
        }
    }

    delete list;
}