#include<iostream>
#include<cstring>
using namespace std;

class Node{
private:
    string word;

    Node* left;
    Node* right;

public:
    Node(){ left = right = NULL; }
    void SetWord(string word){ this->word = word;}
    string GetWord(){ return this->word;}
    void SetLeft(Node* snode){ left = snode;}
    Node* GetLeft(){ return left; }
    void SetRight(Node* snode){ right = snode;}
    Node* GetRight(){ return right; }
};

class Tree{
private:
    Node * rootnode;
public:
    Tree(){ rootnode = NULL; }
    ~Tree(){
        Node * pointer = rootnode;
        if(pointer){
            DelTree(pointer->GetLeft());
            DelTree(pointer->GetRight());
            delete pointer;
        }
    }
    Node * GetRootnode(){ return rootnode; }

    void DelTree(Node * pointer);
    void InsertTree(Node * curnode, string word);
    Node * FindTree(Node * curnode, string word);
    // Node * DeleteTree(Node * curnode, Node * prevnode, string word);
    void PrintTree(string command);

    void PreOrder(Node * curnode);
    void PostOrder(Node * curnode);
    void InOrder(Node * curnode);
};

void Tree::DelTree(Node * pointer){
    if(pointer){
        DelTree(pointer->GetLeft());
        DelTree(pointer->GetRight());
        delete pointer;
    }
}

void Tree::InsertTree(Node * curnode, string word){

    if(rootnode == NULL){
        Node * newnode = new Node;
        newnode->SetWord(word);
        newnode->SetLeft(NULL);
        newnode->SetRight(NULL);
        rootnode = newnode;
    }
    else if(strcmp(curnode->GetWord().c_str(),word.c_str())>0){
        if(curnode->GetLeft()==NULL){
            Node * newnode = new Node;
            newnode->SetWord(word);
            newnode->SetLeft(NULL);
            newnode->SetRight(NULL);
            curnode->SetLeft(newnode);
        }
        else{
            InsertTree(curnode->GetLeft(),word);
        }
    }
    else if(strcmp(curnode->GetWord().c_str(),word.c_str())<0){
        if(curnode->GetRight()==NULL){
            Node * newnode = new Node;
            newnode->SetWord(word);
            newnode->SetLeft(NULL);
            newnode->SetRight(NULL);
            curnode->SetRight(newnode);
        }
        else{
            InsertTree(curnode->GetRight(),word);
        }
    }
}

Node * Tree::FindTree(Node * curnode, string word){
    if(curnode==NULL){
        return NULL;
    }
    if(curnode->GetWord() == word){
        return curnode;
    }
    else if(strcmp((curnode->GetWord()).c_str(),word.c_str())>0){
        return FindTree(curnode->GetLeft(),word);
    }
    else{
        return FindTree(curnode->GetRight(),word);
    }

}

// Node * Tree::DeleteTree(Node * curnode, Node * prevnode, string word){
//     if(curnode==NULL){
//         return NULL;
//     }
//     if(curnode->GetWord() == word){
//         if(curnode->GetLeft()==NULL && curnode->GetRight()==NULL){ //노드가 끝노드일때
//             delete curnode;
//             prevnode->SetLeft(NULL);
//             prevnode->SetRight(NULL);
//             return rootnode;
//         }
//         else if(curnode->GetLeft()==NULL || curnode->GetRight()==NULL){ //자식 노드가 하나만 있을 때
//             if(prevnode->GetLeft()==curnode){ //부모 노드의 왼쪽일때
//                 if(curnode->GetLeft()==NULL){
//                     prevnode->SetLeft(curnode->GetRight());
//                     delete curnode;
//                 }
//                 else if(curnode->GetRight()==NULL){
//                     prevnode->SetLeft(curnode->GetLeft());
//                 }
//                 return rootnode;
//             }
//             else if(prevnode->GetRight()==curnode){ //부모 노드의 오른쪽일때
//                 if(curnode->GetLeft()==NULL){
//                     prevnode->SetRight(curnode->GetRight());
//                     delete curnode;
//                 }
//                 else if(curnode->GetRight()==NULL){
//                     prevnode->SetRight(curnode->GetLeft());
//                 }
//                 return rootnode;
//             }
//         }
//         else{ //자식 노드가 두개일때
//             Node * minnode = curnode->GetRight();
//             Node * upminnode = curnode;
//             while(minnode->GetLeft()){
//                 upminnode = minnode;
//                 minnode = minnode->GetLeft();
//             }
//             curnode->SetWord(minnode->GetWord());
//             upminnode->SetLeft(minnode->GetRight());
//             delete minnode;
//             return rootnode;
//         }
//     }
//     else if(strcmp((curnode->GetWord()).c_str(),word.c_str())>0){
//         return DeleteTree(curnode->GetLeft(),curnode,word);
//     }
//     else if(strcmp((curnode->GetWord()).c_str(),word.c_str())<0){
//         return DeleteTree(curnode->GetRight(),curnode,word);
//     }
// }


void Tree::PrintTree(string command){
    if(command == "PRE"){
        PreOrder(rootnode);
    }
    else if(command == "POST"){
        PostOrder(rootnode);
    }
    else if(command == "IN"){
        InOrder(rootnode);
    }
}

void Tree::PreOrder(Node * curnode){
    if(curnode){
        cout<<curnode->GetWord()<<' ';
        PreOrder(curnode->GetLeft());
        PreOrder(curnode->GetRight());

    }
}

void Tree::PostOrder(Node * curnode){
    if(curnode){
        PostOrder(curnode->GetLeft());
        PostOrder(curnode->GetRight());
        cout<<curnode->GetWord()<<' ';
    }
}

void Tree::InOrder(Node * curnode){
    if(curnode){
        InOrder(curnode->GetLeft());
        cout<<curnode->GetWord()<<' ';
        InOrder(curnode->GetRight());
    }
}

int main(){
    string command;
    Tree * tree = new Tree;
    while(true){
        cin>>command;
        if(command == "INSERT"){
            cin>>command;
            tree->InsertTree(tree->GetRootnode(),command);
        }
        
        else if(command == "FIND"){
            cin>>command;
            if(tree->FindTree(tree->GetRootnode(),command)==NULL){
                cout<<"Not found"<<endl;
            }
            else{
                cout<<command<<" exists"<<endl;
            }
        }

        else if(command == "DELETE"){
            cin>>command;
            // if(tree->DeleteTree(tree->GetRootnode(),tree->GetRootnode(),command)==NULL){
            //     cout<<"Not found"<<endl;
            // }
        }

        else if(command == "PRINT"){
            cin>>command;
            tree->PrintTree(command);
            cout<<endl;
        }

        else if(command == "END"){
            break;
        }
    }

    delete tree;
}