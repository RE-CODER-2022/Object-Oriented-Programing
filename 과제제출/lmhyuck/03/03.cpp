#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class University {

private:
    char U_Name[20]={'\0'};
    int year=0;
    char U_StuID[20]={'\0'};

public:
    University(){}
    // 학번을 반환하는 메소드
    char* saveID() {
        return U_StuID;
    }
    int saveUyear() {
        return year;
    }
    //입력받은 학교명,학번,학년을 저장하는 메소드
    void GiveInfo1(char* _U_Name, char* _U_StuID, int _year) {
        strcpy(U_Name, _U_Name);
        strcpy(U_StuID, _U_StuID);
        year = _year;
    }//학교명,학번,학년 출력 메소드
    void ShowInfo1() {
        cout << "학교: " << U_Name << endl;
        cout << "학번: " << U_StuID << endl;
        cout << "학년: " << year << endl;
    }
    ~University() {}
};

class ComInfo :public University {
private:
    char Object_Oriented_Programing='\0';
    char Digital_Logic_Circuit='\0';

public:
    char saveOOP() {
        return Object_Oriented_Programing;
    }
    char saveDLC() {
        return Digital_Logic_Circuit;
    }
    //입력받은 객프,디논 학점 저장
    void GiveInfo2(char oop ,char dlc) {
        Object_Oriented_Programing = oop;
        Digital_Logic_Circuit = dlc;
    }//객프,디논 학점 출력
    void ShowInfo2() {
        cout << "객체지향프로그래밍 학점: " << Object_Oriented_Programing << endl;
        cout << "디지털논리회로 학점: " << Digital_Logic_Circuit << endl;
    }
};

class StuInfo :public ComInfo {
private:
    char Name[10]={'\0'};
    int age = 0;

public:
    int Age = 0; 
    StuInfo() { };
    void InputInfo() {
        char uname[20]={'\0'};
        char id[20]={'\0'};
        int uyear = 0;
        char OOP='\0';
        char DLC='\0';
        char name[10]={'\0'};
        cout << "학교 :";
        cin >> uname;
        cout << "학번: ";
        cin >> id;
        cout << "학년 :";
        cin >> uyear;
        GiveInfo1(uname, id, uyear);
        cout << "객체지향프로그래밍 학점 :";
        cin >> OOP;
        cout << "디지털논리회로 학점 :";
        cin >> DLC;
        GiveInfo2(OOP, DLC);
        cout << "이름 :";
        cin >> name;
        cout << "나이 :";
        cin >> Age;
        strcpy(Name, name);
        age = Age;
    }
    //학생이름 비교하는 메소드
    int CmpName(char* _name) {
        return strcmp(_name, Name);
    }//학번 비교하는 메소드
    int CmpId(char* _id) {
        return strcmp(_id, saveID());
    }// 학생 정보를 찾는 메소드
    int CmpInfo(char *name, char*id) {
        int i = CmpName(name);
        if (i == 0) {
            int k = CmpId(id);
            if (k == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
};

int main()
{
    StuInfo **stu=new StuInfo*[100];
    int input = 0;
    int sum = 0;
    for(int n=0;n<100;n++){
        stu[n] = new StuInfo();
    }
    string arr1 = "INSERT";
    string arr2 = "FIND";
    string arr3 = "EXIT";
    string arr;
    while (1)
    {
        int i = 0;
        int k = 0;
        cin >> arr;
        if (arr == arr1)
            input = 1;
        else if (arr == arr2)
            input = 2;
        else
            input = 3;

        switch (input)
        {
        case 1:
            sum++;
            if (sum > 100)
                cout << "Limit Number is 100" << endl;
            else {
                stu[i] = new StuInfo();
                stu[i]->InputInfo();
            }
            break;
        case 2:
            char name[10];
            char id[10];
            cin >> name >> id;
            for (int i = 0; i < sum; i++) {
                k = stu[i]->CmpInfo(name, id);
                if (k == 1) {
                    cout << endl << endl;
                    stu[i]->ShowInfo1();
                    stu[i]->ShowInfo2();
                    break;
                }
            }
            break;
        case 3:
            sum = -1;
            break;
        }
        if (sum > 100)
            break;
        else if (sum == -1) {
            cout << endl;
            break;
        }
    }
    for(int n=0;n<100;n++){
        delete stu[n];
    }
}




