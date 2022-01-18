#include <iostream>
#include <cstring>
using namespace std;

class Universe                              //대학
{
private:
    char U_name[20];
    int year;
    char U_StuID[20];

public:
    Universe(char * universename, char * stu_id, int stu_year)                  //constructor
    {
        //this->U_name = universename;
        strcpy(U_name,universename);
        //this->U_StuID = stu_id;
        strcpy(U_StuID,stu_id);
        this->year = stu_year;
    } 
    Universe()                                                                  //constructor                                      
    {

    }
    char* GetID2()                                                    
    {
        return U_StuID;
    }
    char GetID() const                                                          //acess function
    {
        return *U_StuID;
    }
    int Getyear() const                                                          //acess function
    {
        return year;
    } 
    char GetUName() const                                                        //acess function
    {
        return *U_name;
    }    

    void WriteUname() const                                                      //학교출력
    {
        cout << "학교:" << U_name << endl;
    }
    void WriteUid() const                                                        //학번출력
    {
        cout << "학번:" << U_StuID << endl;
    }
    void WriteYear() const                                                       //학년출력
    {
        cout << "학년:" << year << endl;
    }

};

class ComInfoEng : public Universe          //컴퓨터정보공학
{
private:
    char Object_Oriented_Programing;
    char Digital_Logic_Circuit;

public:
    ComInfoEng(char * universename, char * stu_id, int stu_year, char Object_Oriented_Programing, char Digital_Logic_Circuit)               //constructor
        :Universe(universename,stu_id,stu_year)
    {
        this->Object_Oriented_Programing = Object_Oriented_Programing;
        this->Digital_Logic_Circuit = Digital_Logic_Circuit;
    }
    ComInfoEng()                                                     //constructor
    {

    }
    char GetObject_Oriented_Programing() const                       //acess function
    {
        return Object_Oriented_Programing;
    }
    char GetDigital_Logic_Circuit() const                            //acess function
    {
        return Digital_Logic_Circuit;
    }

    void WriteObject_Oriented_Programing() const                                    //객프성적출력
    {
        cout << "객체지향프로그래밍 학점:" << Object_Oriented_Programing << endl;
    }

    void WriteDigital_Logic_Circuit() const                                         //디논성적출력
    {
        cout << "디지털논리회로 학점:" << Digital_Logic_Circuit << endl;
    }
   
    


};

class StuInfo  : public ComInfoEng          //학생정보
{
private:
    char Name[10];
    int age;

public:
    StuInfo(char * universename, char * stu_id, int stu_year, char Object_Oriented_Programing, char Digital_Logic_Circuit, char * name, int age)        //constructor
        :ComInfoEng(universename, stu_id, stu_year,Object_Oriented_Programing,Digital_Logic_Circuit)
    {
        //this->Name = name;
        strcpy(Name,name);
        this->age = age;

    }    
    StuInfo()                                                          //constructor
    {

    }
    char* GetName2()                                                    
    {
        return Name;
    }

    char GetName() const                                                   //acess function
    {
        //cout << Name <<endl;
        return *Name;
    }
    char GetAge() const                                                //acess function
    {
        return age;
    }
   
    
};

int Findinfo(const char* find, const char* obj)
{
    if(strcmp(find,obj) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}






int main()
{
    
    string work;                    //사용자 입력
    StuInfo arr[100];                //클래스배열
    

    /*클래스에 입력받는 변수*/
    char universename[20];              //학교이름
    int stu_year;                       //학년  
    char stu_id[20];                    //학번
    char Object_Oriented_Programing;    //객프성적
    char Digital_Logic_Circuit;         //디논성적
    char name[10];                      //이름
    int age;                            //나이는출력안하는데 입력 왜받지


    
    int arrindex = 0;                   //클래스배열 인데스변수


    /*FIND시 이용하는 변수*/
    char FindName[10];                  //이름 
    char FindId[20];                    //학번
 
 
    
    


    while(1)
    {
        cin >> work;

        if(work == "INSERT")            //INSERT 입력시 학생정보 입력
        {
            if(arrindex >= 100)
            {   
                cout << "Limit Numbers is 100"; 
            }
            else
            {
                cout << "학교 :";       
                cin >> universename; 
                cout << "학번 :";       
                cin >> stu_id; 
                cout << "학년 :";       
                cin >> stu_year; 
                cout << "객체지향프로그래밍 학점 :";       
                cin >> Object_Oriented_Programing; 
                cout << "디지털논리회로 학점 :" ;       
                cin >> Digital_Logic_Circuit; 
                cout << "이름 :";       
                cin >> name; 
                cout << "나이 :";       
                cin >> age;     

                arr[arrindex] = StuInfo(universename,stu_id,stu_year,Object_Oriented_Programing,Digital_Logic_Circuit,name,age);
                arrindex++;
            }
           
        }
        else if(work == "FIND")
        {
            cin >> FindName >> FindId;                       //이름 학번입력
            
                                              

            for(int i=0; i < arrindex; i++)
            {
                if(Findinfo(FindName, arr[i].GetName2()))           //해당이름을 찾기
                {
                    if(Findinfo(FindId, arr[i].GetID2()))           //해당 학번도 맞는지 확인
                    {
                        cout << endl;
                        cout << endl;
                        /*출력*/
                        arr[i].WriteUname();        
                        arr[i].WriteUid();
                        arr[i].WriteYear();
                        arr[i].WriteObject_Oriented_Programing();
                        arr[i].WriteDigital_Logic_Circuit();
                        break;
                    }
                }
            }
        }
        else{
            break;
        }
        
    }  

   return 0;
}