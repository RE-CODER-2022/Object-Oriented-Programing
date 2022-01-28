#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

class Node
{
    private:
        int data;
    public:
        Node* next;
        Node(){next = NULL;}
        int GetData(){return data;}
        Node* GetNext(){return next;}
        void SetData(int a){data = a;}
        void SetNext(Node* node){next = node;}
};
class List
{
    public:
        Node* head;
        List()
        {
            head = NULL;
        }
        void Revolver();
        void Rotate();
        int Murder();
};

void List::Revolver()
{
    head = new Node;
    head->SetData(1);
    Node* CurrNode = head;
    for(int i = 0;i<5;i++)
    {
        Node* InsertNode = new Node;
        InsertNode->SetData(0);
        head->SetNext(InsertNode);
        head = head->GetNext();
    }
    head->SetNext(CurrNode);
}
void List::Rotate()
{
    int number = rand() %6+1;
    for(int i = 0; i<number ;i++)
    {
        head = head->GetNext();
    }
}
int List::Murder()
{
    int CheckMurder = head->GetData();
    if(CheckMurder == 1)
    {
        cout<<"You Died..."<<endl;
        return 1;
    }
    else if(CheckMurder == 0)
    {
        cout<<"You Survived!!"<<endl;
        head = head->GetNext();
        return 10;
    }
    return 1;
}
int main()
{
    List* list = new List();
    string Shoot = "shoot";
    string Rotate = "rotate";
    string In;
    srand(time(NULL));
    list->Revolver();
    list->Rotate();
    cout<<"Command list(shoot/rotate)"<<endl;
    while(true)
    {
        cout<<"CMD>> ";
        cin>>In;
        if(In.compare(Shoot) == 0)
        {
            if(list->Murder() != 10)
            {
                return 0;
            }
        }
        else if(In.compare(Rotate) == 0)
        {
            list->Rotate();
            system("clear");
            cout<<"Command list(shoot/rotate)"<<endl;
            continue;
        }
        else{
            cout<<"Wrong Command!"<<endl;
            continue;
        }
    }
    return 0;
}