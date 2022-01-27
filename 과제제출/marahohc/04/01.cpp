#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Node {
private:
    char * word;
    Node* next;
public:
    Node(){
        word = NULL;
        next = NULL;
    }
    Node* getnext(){return next;}
    void setnext(Node* NEXT){next= NEXT;}
    void setword(char* WORD) { word = WORD;}
    char* getword(){return word;}
};

class List {
private:
    Node* head;
public:
    List(void) { head = NULL; }
    //~List(void); // 소멸자
    void InsertNode(char * word);
    void DisplayList();
    Node* gethead() { return head; }
    int Compare(char* word);
};

void List::DisplayList(void) {
    Node* cur = NULL;
    cur = head;

    if(cur->getnext() == NULL)
        cout << cur->getword() << "->"<<endl;
    else{
        while (cur!= NULL){
            cout << cur->getword() << "-> "; //wow ->
            cur = cur->getnext();
        }
    }
    cout << endl;
}
void List::InsertNode(char * word) {
    //새로운 노드 생성
    Node* newNode = new Node;
    newNode->setword(word);
    //curr노드가 head에서 시작
    Node* currNode = head;
    //head가 null인 경우 head를 new노드로 지정
    if(head == NULL){
        head = newNode;
        return;
    }
    //맨 끝에 위치한 노드를 찾아주기
    while (currNode->getnext() != NULL) {
        currNode = currNode->getnext();
    }
    //new노드를 마지막 노드의 끝에 붙여줌
    currNode->setnext(newNode);
    newNode->setnext(NULL);
}

int List::Compare(char* curword) {
    Node* nodeinst = head;
    char temp1[2] = {"\0"};
    char temp2[2] = {"\0"};
    if(nodeinst->getnext() == NULL){
        bool comp = 1;

        comp = strcasecmp(curword, nodeinst->getword());

        if (comp == false) {
            cout << "Already Exists" << endl;
            return 0;
        }
        if (nodeinst->getword()[strlen(nodeinst->getword()) - 1] == curword[0])
            return 1;
        else if (nodeinst->getword()[strlen(nodeinst->getword()) - 1] != curword[0]) {
            cout << "Not chained" << endl;
            return 0;
        }
        else
            return 0;
        }
    else{ //node 두 개 이상일 때
        while (nodeinst->getnext() != NULL) {
            int comp = 0;
            comp = strcasecmp(curword, nodeinst->getword());

            if (comp == 0) {
                cout << "Already Exists" << endl;
                if (nodeinst->getword()[strlen(nodeinst->getword()) - 1] != curword[0])
                    cout << "Not chained" << endl;
                return 0;
            }
            nodeinst = nodeinst->getnext();
        }
        if(nodeinst->getword()[strlen(nodeinst->getword()) - 1] >= 65 && nodeinst->getword()[strlen(nodeinst->getword()) - 1]<=90 || curword[0]>=65&&curword[0]<=90){
            temp1[0] = nodeinst->getword()[strlen(nodeinst->getword()) - 1];
            temp2[0] = curword[0];
            
            if (!strcasecmp(temp1,temp2))
                return 1;
            else if (strcasecmp(temp1,temp2)) {
                if(strcasecmp(curword, nodeinst->getword()) == 0){
                    cout << "Already Exists" << endl;
                }
                cout << "Not chained" << endl;
                return 0;
            }
        else 
            return 0;
        }
        if (nodeinst->getword()[strlen(nodeinst->getword()) - 1] == *(curword+0))
            return 1;
        else if (nodeinst->getword()[strlen(nodeinst->getword()) - 1] != curword[0]) {
            if(strcasecmp(curword, nodeinst->getword()) == 0){
                cout << "Already Exists" << endl;
            }
            cout << "Not chained" << endl;
            return 0;
        }
        else 
            return 0;
    }
}


int main(void){
    List* list = new List;
    char* instword = new char[20];
    bool comp = 0;
    cout << "CMD(Word/exit)>>";
    cin >> instword;
    comp = strcmp(instword, "exit");
    if(comp == false)
        return 0;
    list->InsertNode(instword);
    list->DisplayList();
    while (1) {
        instword = new char[20];
        cout << "CMD(Word/exit)>>";
        cin >> instword;
        comp = strcmp(instword, "exit");
        if (comp == false)
            return 0;
        else if (comp == true)
        {
           int i = 0;
           i = list->Compare(instword);
           if (i == 0)
            {
              continue;
            }
           else if (i == 1)
            {
                list->InsertNode(instword);
                list->DisplayList();
            }
        }
    }
    delete[] instword;
    delete[] list;
}