#include<iostream>
#include<cstring>

using namespace std;

class Node{
private:
    string word;
    Node * next;
public:
    Node(){}                                            //생성자
    ~Node(){}                                           //소멸자
    void set_word(string word){ this->word = word; }
    void set_next(Node * nextnode){ next = nextnode; }
    string get_word(){ return word; }
    Node * get_next(){ return next; }
};

class List{
private:
    Node * head;
public:
    List(){head = NULL;}                                //생성자
    ~List(){                                            //소멸자
        Node * curnode = head;
        Node * delnode;
        while(curnode){
            delnode = curnode;
            curnode = curnode->get_next();
            delete delnode;
        }
    }
    void set_head(string word){                 //첫번째 노드 생성(==HEAD)
        Node * newnode = new Node;
        head = newnode;
        head->set_word(word);
        head->set_next(NULL);
    }
    Node * get_head(){ return head; }

    bool FindNode(string word){                 //이전에 입력된 단어 탐색
        Node * curnode = head;
        while(curnode){
            if(!strcasecmp(curnode->get_word().c_str(), word.c_str()))//const?
                return false;
            curnode = curnode->get_next();
        }
        return true;
    }

    Node * InsertNode(string word){             //노드 생성
        Node * curnode = head;
        while(curnode->get_next()!=NULL){
            curnode = curnode->get_next();
        }
        curnode->set_next(new Node);
        curnode = curnode->get_next();
        curnode->set_word(word);
        curnode->set_next(NULL);
        return curnode;
    }

    void PrintNode(){                           //이전에 입력받은 word들 모두 출력
        Node * curnode = head;
        while(curnode){
            cout<<curnode->get_word()<<"->";
            curnode = curnode->get_next();
        }
    }

    bool chainornot(string word){               //이전 단어와 chain인지 판단
        Node * curnode = head;
        while(curnode->get_next()!=NULL){
            curnode = curnode->get_next();
        }
        string prevword = curnode->get_word();
        char w1 = prevword[prevword.length()-1], w2 = word[0];
        if('A'<=w1 && w1<='Z')
            w1+='a'-'A';
        if('A'<=w2 && w2<='Z')
            w2+='a'-'A';
        if(w1==w2)
            return true;
        else
            return false;
    }
};

bool exitornot(string word){                    //입력된 word가 exit인지 판단
    if(!strcasecmp(word.c_str(), "exit"))
        return false;
    return true;
}

int main(){
    string word;
    List * list = new List;

    while(true){
            cout<<endl<<"CMD(Word/exit)>> ";
            cin>>word;
            if(!(list->get_head()) && exitornot(word)){     //노드가 아직 없고, exit을 입력하지 않았을 때
                list->set_head(word);
                list->PrintNode();
            }
            else if(exitornot(word)){                       //노드가 최소 하나 있고, exit을 입력하지 않았을 때
                    if(list->chainornot(word)){             //chain인지 아닌지 판단
                       if(list->FindNode(word)){            //이전에 이미 입력된 단어인지 판단
                            list->InsertNode(word);
                            list->PrintNode();
                        }
                        else
                            cout<<"Already Exists";
                    }
                    else
                       cout<<"Not Chained";
            }
            else if(!exitornot(word))                       //EXIT을 입력하면 종료
                break;
    }

    delete list; //동적할당 해제
    return 0;
}