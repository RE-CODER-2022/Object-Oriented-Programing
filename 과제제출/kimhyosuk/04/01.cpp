#include<iostream>
#include<cstring>
using namespace std;

class Node
{
    public:
        string data;
        Node* next;
        Node(){next=NULL;}
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
        Node* InsertNode(string x);
        Node* DeleteNode(string x);
        Node* FindNode(string x);
        bool IsEmpty(){return head == NULL;}
        void DisplayList();
};
Node* List::InsertNode(string x)
{
    if(IsEmpty() == true)
    {
        head = new Node;
        head->SetData(x);
        return head;
    }
    Node* CurrNode = head;
    while(CurrNode->GetNext())
    {
        CurrNode = CurrNode->GetNext();
    }
    Node* NewNode = new Node;
    NewNode->SetData(x);
    CurrNode->SetNext(NewNode);
    return CurrNode;
}
Node* List::DeleteNode(string x)
{
    Node* deleteNode = head;
    if(IsEmpty() == true)
    {
        return NULL;
    }
    if(head->GetNext()->data == x)
    {
        deleteNode = head;
        head = head->GetNext();
        delete deleteNode;
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
    return CurrNode;
}
Node* List::FindNode(string x)
{
    Node* CurrNode = head;
    if(IsEmpty() == true)
    {
        return NULL;
    }
    while(CurrNode->GetNext() != NULL)
    {
        if(CurrNode->GetData() == x){return CurrNode;}
        CurrNode = CurrNode->GetNext();
    }
    return NULL;
}
void List::DisplayList()
{
    Node* CurrNode = head;
    while(CurrNode != NULL)
    {
        cout<<CurrNode->GetData();
        cout<<"-->";
        CurrNode = CurrNode->next;
    }
    cout<<endl;
}
int main()
{
    List* list = new List();
    string word;
    char FWord;
    char BWord;
    cout<<"CMD(Word/exit)";
    cin >> word;
    if(word.compare("exit") == 0){return 0;}
    list->InsertNode(word);
    list->DisplayList();
    BWord = word.back();
    if(BWord <97)
    {
        BWord += 32;
    }
    while(true)
    {
        cout<<"CMD(Word/exit)";
        cin>>word;
        if(word.compare("exit") == 0){return 0;}
        FWord = word.front();
        if(FWord<97)
        {
            FWord += 32;
        }
        if(list->FindNode(word) == NULL)
        {
            if(BWord == FWord)
            {
                cout<<"CMD(Word/exit)";
                list->InsertNode(word);
                list->DisplayList();
                BWord = word.back();
                if(BWord <97)
                {
                    BWord +=32;
                }
            }
            else if(BWord != FWord)
            {
                cout<<"Not Chained"<<endl;
                list->DisplayList();
            }
        }
        else if(list->FindNode(word) != NULL)
        {
            cout<<"Already Exists"<<endl;
            return 0;
        }
    }
    delete list;
    return 0;
}