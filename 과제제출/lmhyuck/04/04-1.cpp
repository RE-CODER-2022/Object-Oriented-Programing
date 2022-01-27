#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int n = 0;
class Node {
private:
    char Data[20] = { '\0' };
public:
    Node* next;
    void set_word(char* data) {
        strcpy(Data, data);
    }
    char* get_word() {
        return Data;
    }
};

class List {
private:
    Node* head;
public:
    int a = 0;
    int c = 0;
    List() { head = nullptr; }
    //단어의 중복을 확인하는 메소드
    int checkdup( char* data) {
        if (c == 0) {
            c++;
            return 1;
        }
        else {
            Node* curr = head;
            while (curr != nullptr) {
                //대소문자 관계없이 중복 단어 골라내기
                a = strcasecmp(curr->get_word(), data);
                if (a == 0) {
                    cout << "Already Exist" << endl;
                    return a;
                    break;
                }
                else
                    curr = curr->next;
            }
            return 1;
        }
    }
    //리스트에 끝말이 이어진 단어를 삽입하는 메소드
    void InsertWord(char* data) {
        Node* inst = new Node;
        inst->set_word(data);
        inst->get_word();
        if (!head) {
            head = inst;
            n = 1;
            return;
        }
        Node* inst_prev = head;
        while (inst_prev->next != nullptr) {
            inst_prev = inst_prev->next;
        }
        int len = strlen(inst_prev->get_word());
        //대소문자 관계없이 진행하기 위함
        if(data[0] > 64 && data[0] < 91){
            if(inst_prev->get_word()[len - 1]> 64 && inst_prev->get_word()[len - 1] < 91){
                if (inst_prev->get_word()[len - 1] == data[0]){
                    inst_prev->next = inst;
                    n = 1;
                }
                else {
                    cout << "Not Chained" << endl;
                    n = 0;
                }  
            }
            else{
                if (inst_prev->get_word()[len - 1] == data[0]+32){
                    inst_prev->next = inst;
                    n = 1;
                }
                else {
                    cout << "Not Chained" << endl;
                    n = 0;
                }
            }
        }
        else{
            if(inst_prev->get_word()[len - 1]> 64 && inst_prev->get_word()[len - 1] < 91){
                if (inst_prev->get_word()[len - 1] == data[0]-32){
                    inst_prev->next = inst;
                    n = 1;
                }
                else {
                    cout << "Not Chained" << endl;
                    n = 0;
                }
            }
            else{
                if (inst_prev->get_word()[len - 1] == data[0]){
                    inst_prev->next = inst;
                    n = 1;
                }
                else {
                    cout << "Not Chained" << endl;
                    n = 0;
                }
            }
        }
    }
    //현재 진행중인 끝말잇기 리스트를 보여주는 메소드
    void printlist() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->get_word() << "->";
            current = current->next;
        }
        cout << endl;
    }
    ~List(){}
};

int main(){
    List* list = new List();
    Node* head = nullptr;
    int input = 0;
    int a= 0;
    char arr[10] = "exit";
    char word[20] = { '\0' };
    while (1)
    {
        cout << "CMD(Word/exit)>> ";
        cin >> word;
        input = strcmp(word, arr);
        if (input) {
            a = list->checkdup(word);
            if (a == 1) {
                list->InsertWord(word);
                if (n == 1)
                    list->printlist();
            }
        }
        else {
            cout << "Program End" << endl;
            break;
        }
    }
    delete list;
    return 0;
}