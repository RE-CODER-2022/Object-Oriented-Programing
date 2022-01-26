#include <iostream>
#include <cstring>
using namespace std;

class Node{
private:
    string data;
public:
    Node* next;
    string Getdata(){return data;}                          //data access function
    void Setdata(string data){this->data = data;}         
};

class List
{
private:
    
public:
    Node* head;                                 //머리front 
    Node* tail;                                 //이전 node를 가리키는 node

    List() { head = NULL; }                     //constructor
    ~List()                                     //destructor
    {
        // Node* x;             //메모리해제를 위한 변수
        // Node* ptr;           //메모리해제를 위한 변수22
        // while(x->next != NULL)
        // {
        //     x = ptr;
        //     ptr = ptr->next;
        //     delete x;
        // }
    }

    void InsertNode(int i,string x)                   //노드를 삽입하는 것 i는 몇번째 node인지 x는 data
    {   
        Node* newNode = new Node();                   //노드를 하나 만들어 메모리를 할당       
        int currIndex = 1;                            //tail의 위치를 잡아주기 위한 변수
        
        newNode -> Setdata(x);                        //data 저장
        newNode -> next = NULL;                       //새로운 node 즉 마지막으로 추가된 node의 next는 NULL
        

        if(head == NULL)                            //check first node
        {
            head = newNode;                         //head 초기화
            tail = head;       
        }
        else                                        //add new node 
        {
            tail = head;                            //tail의 위치 초기값은 head
            while (tail && i - 1 > currIndex)       //while문에 따라 가장 마지막에 추가된 node의 전 node에 위치
            { 
                tail = tail->next;                  
                currIndex++;
            }
          //  newNode->next = tail->next;
            tail->next = newNode;                   //newnode연결
        }
              
    }


    void DisplayList()           //노드 보여주는 것
    {
        Node* cur = head;
        while(cur != NULL)
        {
            cout << cur->Getdata();
            cout << "-->";
            cur = cur->next;
        }

    };       

    bool IsAlreadyExit(string x)            //Already exit
    {
        Node* check = head;                 //node들을 확인하기위한 node
        while(check != NULL)
        {
            if(!strcasecmp(check->Getdata().c_str(),x.c_str()))       //Already exit
            {
                return 1;
            }            
            check = check->next;
        }
        return 0;                           //not exit

    };                    
};


int main()
{
    List* game = new List;         //node
    int index = 1;          //index
    string input;       //input
    string finput;      //먼저입력된 input

    string input_front;  //input의 첫글자
    string finput_back;     //finput의 마지막 글자
    string equal = "exit";       //input 비교
    
    
    cout << "CMD(Word/exit)>>" ;
    cin >> input;
    if(input == equal)                  //exit입력 시 종료
    {
        delete game;
        return 0;
    }
    game->InsertNode(index,input);      //input 노드에 저장
    game->DisplayList();            //show
    cout << endl;
    index++;

    finput = input;                     //먼저 입력된 input저장


    while(1)
    {
        cout << "CMD(Word/exit)>>" ;
        cin >> input;
        // if(game->IsAlreadyExit(input))             //이미존재하는지
        // {
        //     //cout << endl;
        //     cout << "Already Exits";
        //     cout << endl;
        // }
        input_front = input.front();            //input의 앞글자 추출
        finput_back = finput.back();            //finput의 뒷글자 추출
        if(!strcasecmp(input.c_str(), equal.c_str()) )         
        {
            break;                      //exit입력 시 종료
        }
        else if(game->IsAlreadyExit(input))                                 //이미존재하는지
        {
            cout << "Already Exits";
            cout << endl;
        }
        else if(!strcasecmp(input_front.c_str(), finput_back.c_str()))      //끝말잇기 성공
        {
            game->InsertNode(index,input);
            game->DisplayList();       
            cout << endl;
            index++;
        }        
        else{                                                               //끝말잇기 실패
            cout << "Not Chained";
            cout << endl;
            game->DisplayList();
            cout << endl;
        }
        finput = input;
        
    }
    

    delete game;
    
    return 0;
    
    
}