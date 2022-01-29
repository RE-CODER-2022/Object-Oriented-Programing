#include<iostream>
#include<cstring>
using namespace std;
class Node
{
    public:
        string data;
        Node* next;
        Node(){next = NULL;}
        string GetData(){return data;}
        Node* GetNext(){return next;}
        void SetData(string a){data = a;}
        void SetNext(Node*node){next = node;}
};
class List
{
    public:
        Node* head;
        List()
        {
            head = NULL;
        }
        Node* InsertWord(string x);
        Node* DeleteWord(string x);
        string FindWord(string x);
        bool IsEmpty(){return head == NULL;}
        void DisplayList();
};
Node* List::InsertWord(string x)
{
    Node* HeadNode = head;
    Node* InsertNode = head;
    Node* NewNode = new Node;
    NewNode->SetData(x);
    char FWord = x.front();
    if(IsEmpty() == true)
    {
        head = new Node;
        head->SetData(x);
        DisplayList();
        return head;
    }
    while(true)
    {
        if(InsertNode->GetData().front() > FWord)
        {
            NewNode->SetNext(InsertNode);
            break;
        }
        else if(InsertNode->GetData().front() < FWord)
        {
            if(InsertNode->GetNext() == NULL)
            {
                InsertNode->SetNext(NewNode);
                break;
            }
            InsertNode = InsertNode->GetNext();
        }
        else if(InsertNode->GetData().front() == FWord)
        {
            if(x.length() < InsertNode->GetData().length())
            {
                NewNode->SetNext(InsertNode);
                break;
            }
            else if(x.length() > InsertNode->GetData().length())
            {
                InsertNode->SetNext(NewNode);
                break;
            }
        }
    }
    DisplayList();
    return NULL;
}
Node* List::DeleteWord(string x)
{
    if(FindWord(x) == "")
    {
        cout<< "Not Found!"<<endl;
        return NULL;
    }
    Node* deleteNode = head;
    if(IsEmpty() == true)
    {
        DisplayList();
        return NULL;
    }
    if(head->GetData() == x)
    {
        deleteNode = head;
        head = head->GetNext();
        delete deleteNode;
        DisplayList();
        return NULL;
    }
    Node* CurrNode = head;
    while(CurrNode->GetNext())
    {
        deleteNode = deleteNode->GetNext();
        if(deleteNode->GetData() == x)break;
        CurrNode = CurrNode->GetNext();
    }
    CurrNode->SetNext(deleteNode->GetNext());
    delete deleteNode;
    DisplayList();
    return CurrNode;
}
string List::FindWord(string x)
{
    Node* CurrNode = head;
    int i = 0;
    if(IsEmpty() == true)
    {
        return "";
    }
    while(CurrNode->GetNext() != NULL)
    {
        if(CurrNode->GetData().compare(x) == 0)
        {
            return CurrNode->GetData();
        }
        else{
            return "";
        }
        CurrNode = CurrNode->GetNext();
        i++;
    }
    return "";
}
void List::DisplayList()
{
    Node* CurrNode = head;
    int i = 0;
    while(CurrNode != NULL)
    {
        cout<<i<<".";
        cout<<CurrNode->GetData()<<endl;
        CurrNode = CurrNode->next;
        i++;
    }
}
int main()
{
    List* list = new List();
    string arr;
    string arr1;
    while(1)
    {
        cin >> arr;
        if(arr.compare("INSERT") == 0)
        {
            cin>>arr1;
            list->InsertWord(arr1);
        }
        else if(arr.compare("DELETE") == 0)
        {
            cin>>arr1;
            list->DeleteWord(arr1);
        }
        else if(arr.compare("FIND") == 0)
        {
            cin>>arr1;
            if(list->FindWord(arr1) != "")
            {
                cout<<list->FindWord(arr1);
            }
            else if(list->FindWord(arr1) == "")
            {
                cout<<"Not Found"<<endl;
            }
        }
        else if(arr.compare("END") == 0)
        {
            return 0;
        }
        else{
            cout<<"다시 입력하세요^^"<<endl;
        }
    }
    return 0;
}