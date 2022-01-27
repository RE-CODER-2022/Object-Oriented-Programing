#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Node {
private:
    char Data[20] = { '\0' };
public:
    Node* next;
    void SetWord(char* data) {
        strcpy(Data, data);
    }
    char* GetWord() {
        return Data;
    }
};

class List {
private:
    Node* head;
public:
    //단어를 사전순으로 삽입하고 리스트를 출력하는 메소드
    void InsertWord(char* data) {
        Node* inst = new Node;
        inst->SetWord(data);
        inst->GetWord();
        if (!head) {
            head = inst;
            return;
        }
        Node* curr = head;
        int count = 0;
        int listcount = 0;
        while (curr != nullptr) {
            curr = curr->next;
            listcount++;
        }
        curr = head;
        while (curr->next != nullptr) {
            if (curr->GetWord()[0] > data[0]) {
                inst->next = curr;
            }
            else {
                for (int i = 0; i < listcount; i++) {
                    if (curr->GetWord()[0] >= data[0]) {
                        if (curr->GetWord()[0] == data[0]) {
                            int currLen = strlen(curr->GetWord());
                            int dataLen = strlen(data);
                            if (currLen > dataLen) {
                                Node* currPrev = head;
                                for (int i = 0; i < count - 1; i++)
                                    currPrev = currPrev->next;
                                currPrev->next = inst;
                                inst->next = curr;
                                return;
                            }
                            else {
                                inst->next = curr->next->next;
                                curr->next = inst;
                                return;
                            }
                        }
                        else {
                            Node* currPrev = head;
                            for (int i = 0; i < listcount - 1; i++) {
                                currPrev = currPrev->next;
                            }
                            currPrev->next = inst;
                            inst->next = curr;
                            return;
                        }
                    }
                    else{
                        curr = curr->next;
                        count++;
                }
            }
        }
    }
    //단어를 찾고 출력하는 메소드
    void FindWord(char* data){
        Node* curr = head;
        int i = 0;
        while (curr != nullptr) {
            if (strcmp(curr->GetWord(), data) == 0) {
                cout << i << ". " << data << endl;
                return;
            }
            else {
                curr = curr->next;
                i++;
            }
        }
        cout << "Not found" << endl;
        return;
    }
    //단어를 삭제하고 리스트를 출력하는 메소드
    int DeleteWord(char* data) {
        Node* curr = head;
        int cnt = 0;
        int listcnt = 0;
        while (curr != nullptr) {
            curr = curr->next;
            listcnt++;
        }
        curr = head;
        while (curr != nullptr) {
            if (strcmp(curr->GetWord(), data) == 0) {
                if (cnt == 0) {
                    head = head->next;
                    return 0;
                }
                else if (cnt == listcnt) {
                    for (int i = 0; i < cnt-1; i++)
                        curr = curr->next;
                    curr->next = curr->next->next;
                    return 0;
                }
                else {
                    while (curr->next != NULL) {
                        if (curr->next->GetWord() == data) {
                            curr->next = curr->next->next;
                            return 0;
                        }
                        curr = curr->next;
                    }
                }
                return 0;
            }
            else {
                curr = curr->next;
                cnt++;
            }
        }
        cout << "Not found" << endl;
        return 1;
    }
    void PrintWord() {
        Node* curr = head;
        int i = 0;
        while (curr != nullptr) {
            cout << i << ". " << curr->GetWord() << endl;
            curr = curr->next;
            i++;
        }
        cout << endl;
    }
};

int main() {
    List* list = new List();
    char data[20] = { "\0" };
    int input = 0;
    string arr = "\0";
    string arr1 = "INSERT";
    string arr2 = "FIND";
    string arr3 = "DELETE";
    string arr4 = "END";
    if (arr == arr1)
        input = 1;
    else if (arr == arr2)
        input = 2;
    else if (arr == arr3)
        input = 3;
    else
        input = 4;
    while (1) {
        cin >> arr;
        switch (input) {
        case 1:
            cin >> data;
            list->InsertWord(data);
            list->PrintWord();
            break;
        case 2:
            cin >> data;
            list->FindWord(data);
            break;
        case 3:
            cin >> data;
            if (list->DeleteWord(data) == 0)
                list->PrintWord();
            break;
        case 4:
            input = 5;
        }
        if (input == 5)
            break;
    }
    delete list;
    return 0;
}