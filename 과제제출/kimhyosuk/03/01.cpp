#include<iostream>
#include<cstring>
using namespace std;

class University
{
private:
    char U_name[20] = { };
    int Year = 0;
    char U_StuID[20]  = { };

public:
    char* ret_StuID()
    {
        return U_StuID;//변수값이 private라서 학생정보에 값을 반환해주는 용도
    }
    char* ret_name()
    {
        return U_name;//변수값이 private라서 학생정보에 값을 반환해주는 용도
    }
    int ret_Year()
    {
        return Year;
    }
    int Compare_ID(char* stuid)
    {
        int a;
        a = strcmp(U_StuID,stuid);
        return a;
    }
    //INSERT용 입력받은 값 저장하는 메소드
    void in_info_Uni(char* U__name,char* U__StuID,int _year)
    {
        strcpy(U_name,U__name);
        strcpy(U_StuID,U__StuID);
        Year = _year;
    }
    //FIND용 입력받은 값 출력하는 메소드
    void Out_info_Uni()
    {
        cout<<"학교 :"<<U_name<<endl;
        cout<<"학번 :"<<U_StuID<<endl;
        cout<<"학년 :"<<Year<<endl;
    }
};
                       
class ComputerEngineering :public University
{ 
private:
    char Object_Oriented_Programming = '\0';                            
    char Digital_Logic_Circuit = '\0';
public:
    char ret_OOP()
    {
        return Object_Oriented_Programming;
    }
    char ret_DLC()
    {
        return Digital_Logic_Circuit;
    }
    //INSERT용 입력받은 값 저장하는 메소드
    void in_info_Com(char OOP, char DLC)
    {
        Object_Oriented_Programming = OOP;
        Digital_Logic_Circuit = DLC;
    }
    //FIND용 입력받은 값 출력하는 메소드
    void out_info_Com()
    {
        cout<<"객체지향프로그래밍 학점 :"<<Object_Oriented_Programming<<endl;
        cout<<"디지털논리회로 학점 :"<<Digital_Logic_Circuit<<endl;
    }
};

class Stu_Inform : public ComputerEngineering
{
 private:
    char Name[10] = { };
    int Age = 0;
public:
    Stu_Inform(){};
    //학생 이름과 학년 입력받는 메소드
    void in_info_Stu(char *Student_Name,int Student_Year)
    {
        strcpy(Name,Student_Name);
        Age = Student_Year;
    }
    int Compare_name(char* Student_Name)
    {
        int a;
        a = strcmp(Name,Student_Name);
        return a;
    }
    int Compare_info(char *name, char*stuid) {
        int i = Compare_name(name);
        if (i == 0) {
            int k = Compare_ID(stuid);
            if (k == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    void in_info()//INSERT -> 호출되는 메소드
    {
        char u_name[20] = { };
        int year = 0;
        char u_StuID[20]  = { };
        char object_Oriented_Programming;                            
        char digital_Logic_Circuit;
        char name[10] = { };
        int age = 0;
        cout << "학교 :";
        cin>> u_name;
        cout << "학번 :";
        cin>> u_StuID;
        cout << "학년 :";
        cin>> year;
        cout << "객체지향프로그래밍 학점 :";
        cin>> object_Oriented_Programming;
        cout << "디지털논리회로 학점 :";
        cin>> digital_Logic_Circuit;
        cout << "이름 :";
        cin>> name;
        cout << "나이 :";
        cin>> age;
        in_info_Uni(u_name,u_StuID,year);
        in_info_Com(object_Oriented_Programming, digital_Logic_Circuit);
        in_info_Stu(name,age);
    }
    void out_info()//FIND -> 출력되는 메소드
    {
        cout<<endl<<endl;
        cout<<"학교:"<<ret_name()<<endl;
        cout<<"학번:"<<ret_StuID()<<endl;
        cout<<"학년:"<<ret_Year()<<endl;
        cout<<"객체지향프로그래밍 학점:"<<ret_OOP()<<endl;
        cout<<"디지털논리회로:"<<ret_DLC()<<endl;
    }
};
int main()
{
    Stu_Inform **INFORM = new Stu_Inform*[100];
    for(int i =0 ; i<100;i++)
    {
        INFORM[i] = new Stu_Inform();
    }
    char input[20] = {'\0'};
    char str[4] = {'I','F','E'};
    int count= 0;
    while(true)
    {
        if(count >100)
        {
            cout<<"Limit Number is 100"<<endl;
            break;
        }
        for(int i = 0; i<20;i++)
        {
            input[i] = '\0';
        }
        cin >> input;
        if(input[0] == str[0])
        {
            INFORM[count]->in_info();
            count++;
            continue;
        }
        else if(input[0] == str[1])
        {
            char name[20] = {'\0'};
            char stuID[20] = {'\0'};
            cin>>name>>stuID;
            for(int i =0;i<count;i++)
            {
                int a = INFORM[i]->Compare_info(name,stuID);
                if(a == 1)
                {
                    INFORM[i]->out_info();
                    break;
                }
            }
            continue;
        }
        else{
            cout<<endl;
            break;
        }
        continue;
    }
    for(int i =0 ; i<100;i++)
    {
        delete [] INFORM[i];
    }
    delete [] INFORM;
    return 0;
}