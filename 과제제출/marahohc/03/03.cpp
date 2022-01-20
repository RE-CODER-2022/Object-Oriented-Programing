#include <iostream>
#include <cstring>

using namespace std;

class Univ {
    private:
    char U_Name[20];
    char U_StuID[20];
    int year;

    public:
    char* getUname() {return U_Name;}
    char* getUStuID() {return U_StuID;}
    int getUyear(){return year;}
    void setUall(char *UNAME,char *USTUID,int YEAR) {strcpy(U_Name,UNAME),strcpy(U_StuID,USTUID),year = YEAR;}
    void PrintUniv(){
        cout<<endl<<endl<<"학교:"<<U_Name<<endl;
        cout<<"학번:"<<U_StuID<<endl;
        cout<<"학년:"<<year<<endl;
    }
};

class ComInfo :public Univ {
    private:
    char Object_Oriented_Programing;
    char Digital_Logic_Circuit;
    
    public:
    char getOOPInfo(){return Object_Oriented_Programing;}
    char getDLCInfo(){return Digital_Logic_Circuit;}
    void setComInfo(char OOP,char DLC){Object_Oriented_Programing = OOP, Digital_Logic_Circuit = DLC;}
    void PrintComInfo(){
        cout<<"객체지향프로그래밍 학점:"<<Object_Oriented_Programing<<endl;
        cout<<"디지털논리회로 학점: "<<Digital_Logic_Circuit<<endl;
    }
};

class StuInfo :public ComInfo {
    private:
        char Name[10];
        int age;
    
    public:
    StuInfo() { };
    int stuage=0;
    void INSERT(){
        char uname[20];
        char ustuid[20];
        int uyear=0;
        char oop;
        char dlc;
        char name[10];
        cout<<"학교 :";
        cin>>uname;
        cout<<"학번 :";
        cin>>ustuid;
        cout<<"학년 :";
        cin>>uyear;
        cout<<"객체지향프로그래밍 학점 :";
        cin>>oop;
        cout<<"디지털논리회로 학점 :";
        cin>>dlc;
        cout<<"이름 :";
        cin>>name;
        cout<<"나이 :";
        cin>>stuage;
        setUall(uname,ustuid,uyear);
        setComInfo(oop,dlc);
        strcpy(Name,name);
        age = stuage;
    }

    void PrintAll(){
        PrintUniv();
        PrintComInfo();
    }
    int FIND(char *name,int stuage){
        char instid[10]={"0"};
        strcpy(instid,getUStuID());
        int i = strcmp(name,Name);
        int j = strcmp(name,instid);
        if(i==0||j==0){
           return 1;
        }
        else
           return 0;
    }
};

int main(void) {
    StuInfo **stu = new StuInfo *[100];
    string kase;
    int i=0;
    for(int num=0;num<100;num++){
        stu[num] = new StuInfo();
    }
    while(1){
        cin>>kase;
        if(kase=="INSERT"){
            stu[i] = new StuInfo();
            stu[i]->INSERT();
            i++;
        }
        else if(kase=="FIND"){
            char name[10];
            int ustuid;
            int j = 0;
            cin>> name >> ustuid;
            for(int i=0;i<100;i++){
                j = stu[i]->FIND(name,ustuid);
                if(j == 1){
                    stu[i]->PrintAll();
                    break;
                }
            }
            if(j==0)
                cout<<"없는 학생입니다. 다시 입력해주세요."<<endl;
        }
        else if(kase=="EXIT"){
            delete[] stu;
            return 0;
        }
    }
    delete[] stu;
}