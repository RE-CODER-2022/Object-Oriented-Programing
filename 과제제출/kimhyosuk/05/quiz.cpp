#include<iostream>
#include<string>
using namespace std;

class Node{
    private:
        string data;
        Node* left;
        Node* right;
    public:
        Node(string _data)
        {
            this->data = _data;
            left = NULL;
            right = NULL;
        }
        string GetData(){return data;}
        Node* GetLeft(){return left;}
        Node* GetRight(){return right;}
        void SetData(string _data){this->data = _data;}
        void SetLeft(Node* _data){this->left=_data;}
        void SetRight(Node* _data){this->right=_data;}
};
class Tree{
    private:
        Node* root;
    public:
        Node* GetRoot(){return root;}
        Node* SearchTree(Node* tree,string _data);
        void InsertTree(string _data,Node* t);
        Node* SearchDelTree(Node* tree);
        Node* DeleteTree(Node* tree,Node* parent,string _data);
        void PrintTreePre(Node* tree);
        void PrintTreeIn(Node* tree);
        void PrintTreePost(Node* tree);
        Tree() : root(NULL){}
};
Node* Tree::SearchTree(Node* tree,string _data)
{
    if(tree == NULL)
        return NULL;
    if(tree->GetData().compare(_data) == 0)
        return tree;
    else if(tree->GetData().compare(_data) > 0)
        return SearchTree(tree->GetLeft(),_data);
    else if(tree->GetData().compare(_data) < 0)
        return SearchTree(tree->GetRight(),_data);
    return NULL;
}
void Tree::InsertTree(string _data,Node* t)
{
    Node* Newnode = new Node(_data);
    Node* tmpRoot = NULL;
    if(!root)
        root = Newnode;
    else{
        Node* tmpRoot1 = root;
        while(tmpRoot1 != NULL)
        {
            tmpRoot = tmpRoot1;
            if(Newnode->GetData().compare(tmpRoot->GetData()) < 0)
                tmpRoot1 = tmpRoot1->GetLeft();
            else if(Newnode->GetData().compare(tmpRoot1->GetData()) > 0)
                tmpRoot1 = tmpRoot1->GetRight();
            else
                return;
        }
        if(Newnode->GetData().compare(tmpRoot->GetData()) == 0)
            tmpRoot->SetRight(Newnode);
        else
            tmpRoot->SetLeft(Newnode);
    }
}
Node* Tree::SearchDelTree(Node* tree)
{
    if(tree == NULL)
        return NULL;
    if(tree->GetLeft() == NULL)
        return tree;
    else
        return SearchDelTree(tree->GetLeft());
}
Node* Tree::DeleteTree(Node* tree,Node* parent,string _data)
{
    if(tree == NULL)
        return NULL;
    Node* removeNode = NULL;
    if(tree->GetData().compare(_data) > 0)
        removeNode = DeleteTree(tree->GetLeft(),tree,_data);
    else if(tree->GetData().compare(_data) < 0)
        removeNode = DeleteTree(tree->GetRight(),tree,_data);
    else if(tree->GetData().compare(_data) == 0){
        removeNode = tree;
        if(tree->GetLeft() == NULL && tree->GetRight() == NULL){
            if(parent->GetLeft() == tree)
                parent->GetLeft() == NULL;
            if(parent->GetRight() == tree)
                parent->GetRight() == NULL;
        }
        else if(tree->GetLeft() == NULL || tree->GetRight() == NULL)
        {
            Node* tmp = NULL;
            if(tree->GetLeft() != NULL)
                tmp = tree->GetLeft();
            else
                tmp = tree->GetRight();
            if(parent->GetLeft() == tree)
                parent->SetLeft(tmp);
            else
                parent->SetRight(tmp);
        }
        else if(tree->GetLeft() != NULL && tree->GetRight() !=NULL){
            Node* minNode = SearchDelTree(tree->GetRight());
            minNode = DeleteTree(tree,NULL,minNode->GetData());
            tree->GetData() = minNode->GetData();
        }
    }
    return removeNode;
}
void Tree::PrintTreePre(Node* tree)
{
    if(!tree)
        return;
    cout<<tree->GetData()<<" ";
    if(tree->GetLeft())
        PrintTreePre(tree->GetLeft());
    if(tree->GetRight())
        PrintTreePre(tree->GetRight());
}
void Tree::PrintTreeIn(Node* tree)
{
    if(!tree)
        return;
    if(tree->GetLeft())
        PrintTreeIn(tree->GetLeft());
    cout<<tree->GetData()<<" ";
    if(tree->GetRight())
        PrintTreeIn(tree->GetRight());
}
void Tree::PrintTreePost(Node* tree)
{
    if(!tree)
        return;
    if(tree->GetLeft())
        PrintTreePost(tree->GetLeft());
    if(tree->GetRight())
        PrintTreePost(tree->GetRight());
    cout<<tree->GetData()<<" ";
}
int main()
{
    Tree* t = new Tree;
    string _input;
    string _input1;
    char input[50] = {'\0'};
    char input1[50] = {'\0'};
    while(1)
    {
        cout<<"입력하세요: ";
        cin>>input;
        _input = input;
        if(_input.compare("END") == 0)
        {
            cin.clear();
            return 0;
        }
        else{
            cin>>input1;
            _input1 = input1;
            if(_input.compare("INSERT") == 0)
            {
                t->InsertTree(_input1,t->GetRoot());
            }
            else if(_input.compare("FIND") == 0)
                if(t->SearchTree(t->GetRoot(),_input1) != NULL)
                    cout<<t->SearchTree(t->GetRoot(),_input1)->GetData()<<" exists"<<endl;
                else{
                    cout<<"NOT found"<<endl;
                }
            else if(_input.compare("DELETE") == 0){
                if(t->GetRoot()->GetLeft() != NULL)
                {
                    t->DeleteTree(t->GetRoot()->GetLeft(),t->GetRoot(),_input1);
                }
                else{
                    cout<<"NOT found"<<endl;
                }   
            } 
            else if(_input.compare("PRINT") == 0)
            {
                if(_input1.compare("PRE") == 0)
                    t->PrintTreePre(t->GetRoot());
                else if(_input1.compare("IN") == 0)
                    t->PrintTreeIn(t->GetRoot());
                else if(_input1.compare("POST") == 0)
                    t->PrintTreePost(t->GetRoot());
            }
        }
        cin.ignore();
    }
}