#include <iostream>
#include <string>

using namespace std;

class Node{
private:
    string s;
    Node* right;
    Node* left;

public:
    Node(){right=NULL; left=NULL;}
    void SetWord(string word){s=word;}
    void SetRight(Node* node){right=node;}
    void SetLeft(Node* node){left=node;}
    string GetWord(){return s;}
    Node* GetRight(){return right;}
    Node* GetLeft(){return left;}
};

class Tree{
private:
    Node* head;

public:
    Tree(){head=NULL;}
    ~Tree(){
        ClearNode(head);
    }
    bool ExistHead(){return head==NULL;}
    void SetHead(string word){
        head=new Node;
        head->SetWord(word);
    };
    Node* GetHead(){return head;}
    void InsertNode(string word);
    int FindNode(string word);
    void PreOrder(Node* node);
    void InOrder(Node* node);
    void PostOrder(Node* node);
    void ClearNode(Node* node);
    void DeleteNode(string word);
};

void Tree::InsertNode(string word)
{
    Node* currnode=head;
    if(ExistHead()==true){
        SetHead(word);
    }
    else{
        while(currnode!=NULL){
            if(currnode->GetWord()>word){
                if(currnode->GetLeft()==NULL){
                    currnode->SetLeft(new Node);
                    currnode=currnode->GetLeft();
                    currnode->SetWord(word);
                    break;
                }
                else{
                    currnode=currnode->GetLeft();
                }
            }
            else if(currnode->GetWord()<word){
                if(currnode->GetRight()==NULL){
                    currnode->SetRight(new Node);
                    currnode=currnode->GetRight();
                    currnode->SetWord(word);
                    break;
                }
                else{
                    currnode=currnode->GetRight();
                }
            }
        }
    }

}

int Tree::FindNode(string word)
{
    Node* currnode=head;
    while(currnode!=NULL){
        if(currnode->GetWord()>word){
            currnode=currnode->GetLeft();
        }
        else if(currnode->GetWord()<word){
            currnode=currnode->GetRight();
        }
        else if(currnode->GetWord()==word){
            return 1;  //존재하면 1, 없으면 0
        }
    }
    return 0;
}

void Tree::PreOrder(Node* node)
{
    if(node!=NULL){
        cout<<node->GetWord()<<" ";
        PreOrder(node->GetLeft());
        PreOrder(node->GetRight());
    }   
}

void Tree::InOrder(Node* node)
{
    if(node!=NULL){
        InOrder(node->GetLeft());
        cout<<node->GetWord()<<" ";
        InOrder(node->GetRight());
    }
}

void Tree::PostOrder(Node* node)
{
    if(node!=NULL){
        PostOrder(node->GetLeft());
        PostOrder(node->GetRight());
        cout<<node->GetWord()<<" ";
    }
}

void Tree::ClearNode(Node* node)
{
    if(node!=NULL){
        ClearNode(node->GetLeft());
        delete node;
        ClearNode(node->GetRight());
    }
}

void Tree::DeleteNode(string word)
{   
    if(FindNode(word)==0)
        cout<<"Not Found"<<endl;
    else{
        Node* currnode=head;
        Node* prevnode;
        while(currnode!=NULL){
            if(currnode->GetWord()>word){
                if(currnode->GetWord()>word){
                    prevnode=currnode;
                    currnode=currnode->GetLeft();
                }
                else if(currnode->GetWord()<word){
                    prevnode=currnode;
                    currnode=currnode->GetRight();
                }
                else if(currnode->GetWord()==word){
                    
                    if(currnode->GetLeft()==NULL&&currnode->GetRight()==NULL){
                        delete currnode;
                        break;
                    }
                    
                    else if(currnode->GetLeft()==NULL&&currnode->GetRight()!=NULL){
                        if(prevnode->GetWord()>currnode->GetWord()){
                            prevnode->SetLeft(currnode->GetRight());
                            delete currnode;
                            break;
                        }
                        else if(prevnode->GetWord()<currnode->GetWord()){
                            prevnode->SetRight(currnode->GetRight());
                            delete currnode;
                            break;
                        }
                    }
                    
                    else if(currnode->GetLeft()!=NULL&&currnode->GetRight()==NULL){
                        if(prevnode->GetWord()>currnode->GetWord()){
                            prevnode->SetLeft(currnode->GetLeft());
                            delete currnode;
                            break;
                        }
                        else if(prevnode->GetWord()<currnode->GetWord()){
                            prevnode->SetRight(currnode->GetLeft());
                            delete currnode;
                            break;
                        }
                    }

                    else if(currnode->GetLeft()!=NULL&&currnode->GetRight()!=NULL){
                        Node* findnode=currnode->GetRight();
                        string x=findnode->GetWord();
                        while(findnode!=NULL){
                            if(x>findnode->GetWord()){
                                x=findnode->GetWord();
                            }
                        }
                    }  //자식을 왼쪽, 오른쪽 모두 가지고 있을 때 구현 못함.
                }
            }
        }
    }
}

int main(){
    Tree tree;
    string command;
    while(1){
        cin>>command;
        if(command=="INSERT"){
            string word;
            cin>>word;
            tree.InsertNode(word);
        }
        else if(command=="FIND"){
            string word;
            cin>>word;
            if(tree.FindNode(word)==1)
                cout<<word<<" exists"<<endl;
            else
                cout<<"Not Found"<<endl;
        }
        else if(command=="DELETE"){
            string word;
            cin>>word;
            tree.DeleteNode(word);
        }
        else if(command=="PRINT"){
            string command2;
            cin>>command2;
            if(command2=="PRE"){
                tree.PreOrder(tree.GetHead());
                cout<<endl;
            }
            else if(command2=="POST"){
                tree.PostOrder(tree.GetHead());
                cout<<endl;
            }
            else if(command2=="IN"){
                tree.InOrder(tree.GetHead());
                cout<<endl;
            }
        }
        else if(command=="END"){
            break;
        }
    }

}