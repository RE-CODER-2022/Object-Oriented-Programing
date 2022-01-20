#include <iostream>
#include <string.h>

using namespace std;

class Uni
{
    private:
        char U_Name[20];
        int year;
        char U_StuID[20];

    public:
        void setUname(char *uname){strcpy(U_Name,uname);}
        void setyear(int Year){year=Year;}
        void setUid(char *id){strcpy(U_StuID, id);}
        char* getUid(){return U_StuID;}
        char* getUname(){return U_Name;}
        int getYear(){return year;}

};

class Computer :public Uni
{
    private:
        char Object_Oriented_Programing;
        char Digtal_Logic_Circuit;

    public:
        void setObj(char Ograde){Object_Oriented_Programing=Ograde;}
        void setDig(char Dgrade){Digtal_Logic_Circuit=Dgrade;}
        char getObj(){return Object_Oriented_Programing;}
        char getDig(){return Digtal_Logic_Circuit;}
};

class Infor :public Computer
{
    private:
        char Name[10];
        int age;

    public:
    void setname(char *name){strcpy(Name,name);}
    void setage(int Age){age=Age;}
    char* getname(){return Name;}

};

int main()
{
    int i=0;
    char a[10];
    Infor stu[100];
    while(1){
        cin>>a;

        if(!strcmp(a,"INSERT")){
            char uname[20]={0,},ID[20]={0,},Obgrade={0},Digrade={0},name[10]={0,};
            int year=0,age=0;
            if(i>=100)
            {
                cout<<"Limit Number is 100";
                break;
            }
            cout<<"학교 :"; cin>>uname; stu[i].setUname(uname);
            cout<<"학번 :"; cin>>ID; stu[i].setUid(ID);
            cout<<"학년 :"; cin>>year; stu[i].setyear(year);
            cout<<"객체지향프로그래밍 학점 :"; cin>>Obgrade; stu[i].setObj(Obgrade);
            cout<<"디지털논리회로 학점 :"; cin>>Digrade; stu[i].setDig(Digrade);
            cout<<"이름 :"; cin>>name; stu[i].setname(name);
            cout<<"나이 :"; cin>>age; stu[i].setage(age);
            i++;
        }

        else if(!strcmp(a,"FIND")){
            char Name[10], num_ID[20];
            cin>>Name; cin>>num_ID;
            for(int j=0;j<i;j++){
                if(!strcmp(Name, stu[j].getname())){
                    if(!strcmp(num_ID, stu[j].getUid())){
                        cout<<"학교:"<<stu[j].getUname()<<endl;
                        cout<<"학번:"<<stu[j].getUid()<<endl;
                        cout<<"학년:"<<stu[j].getYear()<<endl;
                        cout<<"객체지향프로그래밍 학점:"<<stu[j].getObj()<<endl;
                        cout<<"디지털논리회로 학점:"<<stu[j].getDig()<<endl;
                        break;
                    }
                }
            }

        }

        else
            break;
    }

    return 0;
}