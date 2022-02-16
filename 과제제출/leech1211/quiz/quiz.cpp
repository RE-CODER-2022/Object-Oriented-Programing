#include <iostream>
#include <cstring>
using namespace std;

class Node {
private:
    string data;        //내용
   
public:
    int sequence;       //순서
    Node* next;
    string Getdata(){return data;}
    void Setdata(string data){this->data = data;}
};

class List{
private:

public:
    Node* head;
    Node* cur;
    Node* pre;

    List() {head = NULL;}

    int Insert(string x, int i)
    {
        Node* newNode = new Node();
        int curIndex = 1;

        newNode -> Setdata(x);
        newNode ->sequence = i;
        newNode -> next = NULL;

        if(head == NULL)        //첫 입력
        {
            head = newNode;
        }
        //cur은 자리가 바뀌어야하는 노드
        //pre는 cur의 바로 앞노드
        else
        {
            cur = head;      
            if(i == 1)
            {
                if(cur->Getdata() > x)      //두번째 노드가 처음으로 들어갈경우
                {
                    newNode->next = cur;    //기존노드를 새노드의 next로
                    head = newNode;         //새노드를 head로
                }
                else
                {
                    cur->next = newNode;
                }
            }
            else
            {
                while (1)
                {
                    if (cur->Getdata() < x) //새로입력된 데이터가 기존의 데이터보다 사전순 뒤일때
                    {
                        if (cur->next == NULL) //기존노드들 모두보다 사전순 뒤일때 즉 이미 맨뒤노드까지 온경우
                        {
                            cur->next = newNode;
                            break;
                        }
                        pre = cur;
                        cur = cur->next;
                    }
                    else //새로 입력된 데이터가 cur의 자리에 들어가야할때
                    {
                        pre->next = newNode;
                        newNode->next = cur;
                        cur->next == NULL; //이 줄은 안해도 되는거 같지만 일단 해줌
                        break;
                    }
                }
               
            }
            
        }
        
    }

    void NumberSort(int n)                           //숫자 재정렬
    {
        Node* cur = head;
        int k=0;
        while(cur != NULL)
        {
            cur->sequence = k;
            cur = cur->next;
            k++;
            //cout << "ok" << endl;
        }

       
    }

    int Delete(string x)
    {
        Node* cur = head;       //삭제할 word를 가리킬 node
        Node* pre = cur;        //삭제할 word 전을 가리킬 node
        while(cur != NULL)
        {
            if(x == cur->Getdata()) //삭제할 node를 찾았다면
            {
                pre->next = cur->next;
                if(cur == head)     //첫 node 삭제시 head 재설정
                {
                    head = pre->next;
                }
                
                delete cur;
                return 0;
                
                
            }
            pre = cur;
            cur = cur->next;
        }
        cout << "Not Found" << endl;

    }

    void Show()
    {
        Node* shownode = head;
        while(shownode != NULL)
        {
            cout << shownode->sequence << "." << shownode->Getdata() << endl;
            shownode = shownode->next;
        }
    }

    int Find(string x)
    {
        Node* check = head;
        while(check != NULL)
        {
            if(x == check->Getdata())       //찾는 단어라면
            {
                cout << check->sequence << "." << check->Getdata() << endl;
                return 0;
            }
            
            check = check->next;
        }        
        //찾는 단어가 없어 함수가 계속 실행 됬다면    
        cout << "Not found" << endl;
            

    }

    bool AlreadyExit(string x)
    {
        Node* check = head;
        while(check != NULL)
        {
            if( !strcmp(x.c_str(), check->Getdata().c_str()))       //이미 단어가 있다면 
            {
                return 0;   //같은경우
            }
            else
            {
                return 1;   //다른경우
            }
            check = check->next;
        }
        return 1;
    }

};

int main()
{
    List* Diction = new List;
    string commend;     //명령입력
    string word;        //단어입력
    int num=0;          //사전적 순서
    string C_insert = "INSERT";
    string C_find = "FIND";
    string C_delete = "DELETE";
    string C_end = "END";

    while(1)
    {
        cin >> commend; 

        if(commend == C_end)        //프로그램 종료
        {
            delete Diction;
            return 0;
        }
    
        cin >> word;
        
        if(commend == C_insert)
        {
            
            if(Diction->AlreadyExit(word) == 0)     //이미 단어가 있다면
            {
                Diction -> Show();
            }
            else                                    //없는 단어라면
            {         
                Diction -> Insert(word,num);   
                cout << "num: " << num << endl;
                Diction -> NumberSort(num);         
                Diction -> Show();                
            }
            num++;
                      
        }
        else if(commend == C_find)
        {
            Diction->Find(word);
        }
        else if(commend == C_delete)        
        {
            Diction->Delete(word);
            num--;
            Diction -> NumberSort(num);  
            Diction->Show();
        }
        else
        {
            
        }
        
       
    }
    

    delete Diction;
    //DELETE에 세그폴트
   
    


}