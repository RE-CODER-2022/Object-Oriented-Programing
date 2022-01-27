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
/*-------------------------------------------------------------------------------------------------------------------
커맨드를 다 짜고나서 정렬해주는 코드를 넣어주려고 하니 이미 짜놓은 틀에 맞추어 주려고 코드가 못생겼습니다
예외처리를 일일이 해줬는데 아직 더 숨어있는 오류가 있을수도 ㅜㅜㅜ
그리고 코드 다짰다가 뭐 잘못해서 다 날아가서 다시 짠거라 가지구 오류있으면 피드백 부탁드립니다*/
        else
        {
            cur = head;
            //cout << i << endl;
            while((cur && i > curIndex) || i == 1)           
            {
                if(cur->Getdata() > x)          //사전식 정렬
                {
                    pre = cur;
                    if(cur == head)             //맨처음으로 들어갈경우
                    {
                        head = newNode;         
                        newNode->next = cur;
                        return 0;
                    }
                    else                        //중간에 들어가는 경우
                    {
                        pre->next = newNode;
                        newNode->next = cur;
                        //cur->next = NULL;
                        return 0;
                    }             
                }
                if(i == 1)
                {
                    break;
                }
                if(i >= 2)
                {
                    
                    cur = cur->next;
                }
                curIndex++;

                
            }
            cur->next = newNode;
        }
        
    }

    void NumberSort(int n)                           //숫자 재정렬
    {
        Node* cur = head;
        int k=0;

        // for (int k = 0; k <= n; k++)
        // {
        //     //cout << "asd" << endl;
        //     cur->sequence = k;
        //     cur = cur->next;
        // }
        while(cur != NULL)
        {
            cur->sequence = k;
            cur = cur->next;
            k++;
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
                //cout << "INSERT" << endl;
                Diction -> NumberSort(num);         
                Diction -> Show();                
            }
            
                      
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
        num++;
       
    }
    

    delete Diction;
    //DELETE에 세그폴트
   
    


}