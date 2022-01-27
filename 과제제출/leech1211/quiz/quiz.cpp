#include <iostream>
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

    List() {head = NULL;}

    void Insert(string x, int i)
    {
        Node* newNode = new Node();
        int curIndex = 1;

        newNode -> Setdata(x);
        newNode ->sequence = i;
        newNode -> next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            cur = head;
            while(cur && i > curIndex)
            {
                cur = cur->next;
                curIndex++;
            }
            cur->next = newNode;
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
                break;
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
            if(x == check->Getdata())       //이미 단어가 있다면 
            {
                return 0;
            }
            else
            {
                return 1;
            }
            check = check->next;
        }
        return 1;
    }

    // void Sort(int n)                             //사전순으로 정렬
    // {
    //     Node* check = head;
    //     Node* temp;
    //     int numtemp;
    //     for(int i=0;i<n;i++)
    //     {
    //         check = head;
    //         for(int j=0;j<n;j++)
    //         {
    //             if(check > check->next)
    //             {
    //                 temp = check;
    //                 check = check->next;
    //                 check->next = temp;
    //             }
    //             check = check->next;
    //         }
    //     }

    //     for(int i=0;i<n;i++)                     //숫자도 정렬
    //     {
    //         check = head;
    //         for(int j=0;j<n;j++)
    //         {
    //             if(check->sequence > check->next->sequence)
    //             {
    //                 numtemp = check->sequence;
    //                 check->sequence = check->next->sequence;
    //                 check->next->sequence = numtemp;
    //             }
    //             check = check->next;
    //         }
    //     }
    // }

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
                //Diction -> Sort(num);               //정렬           
                Diction -> Show();                
            }
            num++;            
        }
        else if(commend == C_find)
        {
            Diction->Find(word);
        }
        else if(commend == C_delete)        //오류  
        {
            Diction->Delete(word);
            Diction->Show();
        }
    }
    

    delete Diction;
    //숫자 바꿔주기
    //사전순으로 재배치
    


}