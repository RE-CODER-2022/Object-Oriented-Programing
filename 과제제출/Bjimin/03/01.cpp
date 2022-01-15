#include<iostream>
#include<cstring>

using namespace std;

class Uni{
private:
    char U_Name[20];
    int year;
    char U_StuID[20];   
public:
    void Uni_in(string Uname, string Ustuid, int Uyear);
    int finduserid(string userid);
    void Uni_print();
};


class Computer_information : public Uni{
private:
    char Object_Oriented_Programing;
    char Digtal_Logic_Circuit;
public:
    void grade_in(char Ograde, char Dgrade);
    void grade_print();
};


class Student : public Computer_information{
private:
    char Name[10];
    int age;

public:
    void student_in(string Uname, string Ustuid, int Uyear,char Ograde, char Dgrade, string username, int userage);
    void find(string username, string userid);
};



int main(){
    Student * stu[100];
    string Beh; //실행할 기능 문자열 입력받는 변수
    int i=0;

    string univ, userid, username;
    int univyear,age;
    char Objectgrade, digitalgrade;

    while(1){

        cin>>Beh; //어떤 기능 실행할지 입력

        if (Beh=="INSERT"){
            if(i>=100){ //입력이 100번 넘으면 더이상 입력 불가
                cout<<"Limit Number is 100"<<endl;
            }
            else{
                stu[i] = new Student;

                cout<<"학교 :";
                cin>>univ;
                cout<<"학번 :";
                cin>>userid;
                cout<<"학년 :";
                cin>>univyear;
                cout<<"객체지향프로그래밍 학점 :";
                cin>>Objectgrade;
                cout<<"디지털논리회로 학점 :";
                cin>>digitalgrade;
                cout<<"이름 :";
                cin>>username;
                cout<<"나이 :";
                cin>>age;

                stu[i]->student_in(univ,userid,univyear,Objectgrade,digitalgrade,username,age);

                i++;
            }
        }
        else if(Beh=="FIND"){

            cin>>username>>userid;

            for(int j=0; j<i; j++){ 
                stu[j]->find(username,userid);
            }

        }
        else if(Beh=="EXIT"){
            for(int j=0; j<=i; j++){
                delete stu[i];
            }
            break;
        }
    }
}

//각 클래스의 변수에 학생 정보를 입력하는 함수들
void Uni::Uni_in(string Uname, string Ustuid, int Uyear){
    strcpy(U_Name,Uname.c_str()); //string.c_str() : string 문자열의 첫번째 문자의 주소를 반환한다.
    strcpy(U_StuID,Ustuid.c_str());
    year = Uyear;
}

void Computer_information::grade_in(char Ograde, char Dgrade){
        Object_Oriented_Programing = Ograde;
        Digtal_Logic_Circuit = Dgrade;
    }

void Student::student_in(string Uname, string Ustuid, int Uyear,char Ograde, char Dgrade, string username, int userage){
        Uni_in(Uname,Ustuid,Uyear);
        grade_in(Ograde,Dgrade);
        strcpy(Name,username.c_str());
        age = userage;
    }


//find 실행 시 찾고자 하는 정보를 이전에 입력받은 정보와 비교하여 찾아내는 함수
void Student::find(string username, string userid){
    if(username==Name){
        if(finduserid(userid)){
            grade_print();
        }
    }
}
int Uni::finduserid(string userid){
    if(userid==U_StuID)
        return 1;
    else
        return 0;
}


//find 후 정보 출력하는 함수
void Uni::Uni_print(){
        cout<<endl<<endl<<"학교:"<<U_Name<<endl;
        cout<<"학번:"<<U_StuID<<endl;
        cout<<"학년:"<<year<<endl;
    }

void Computer_information::grade_print(){
        Uni_print();
        cout<<"객체지향프로그래밍 학점:"<<Object_Oriented_Programing<<endl;
        cout<<"디지털논리회로 학점:"<<Digtal_Logic_Circuit<<endl;
    }