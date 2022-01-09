#include <iostream>
#include<cstdlib>       //Random number     rand(),srand()
#include<ctime>         //Random number time seed  
using namespace std;

void Sender();
void Transmission_Process(const char* data);
void Receiver(const char* data);


int main()
{
    Sender();       
}

void Sender()        //암호화
{
    char* input;      //입력값
    int checksum;   //각자리수의 합
    int* checksumptr = &checksum;   //checksum을 가리키는 ptr
    
    input = new char[5];
    cout << "Data : ";  
    cin >> input;       //입력

    checksum = (int(input[0])-48) + (int(input[1])-48) + (int(input[2])-48) + (int(input[3])-48);   //숫자 0의 아스카코드가 48이므로 input[x]-48은 해당요소의 숫자를 나타냄

    if(checksum > 9)        //checksum이 10을 넘을경우 뒷자리만
    {
        checksum = checksum % 10;
    }
    
    input[4] = (char)checksum + 48;   //맨뒷자리 checksum 추가
 
    cout<<"Send Data:"<<input<<endl;
    Transmission_Process(input);
    delete[] input;
   
}

void Transmission_Process(const char* data)
{
    int error;          //에러가 날 확률
    int wrongnum;       //잘못된 숫자 
    int index;          //몇번째 숫자가 변경될지 랜덤으로 결정되는 요소
    char temparr[5];   //const로 전달된 data를 다루기 위한 임시배열

    char* temp2 = new char[5];
    

    for(int i=0;i<5;i++)                //temparr로 data복사
    {
        temparr[i] = data[i];
    }

    srand((unsigned int)time(NULL));    //seed값으로 현재시간 부여  
    error = rand() % 10;                //에러가 날 확률
    index = rand() % 4;                 //에러가 날 경우 바뀌게 될 인덱스
    wrongnum = rand() % 10;             //wrongnum 생성
    
    
    if(error <= 3)  //0~9 10개의 숫자중에 0,1,2,3 네개의 숫자에 해당되는 경우 즉 40%의 확률
    {
        do                                              //에러로 인해 랜덤으로 결정된 숫자가 기존 숫자와 같을 경우
        {                                               //즉 에러로 인해 4라는 숫자를 대신할 숫자가 랜덤으로 4가 결정되었을때
             wrongnum = rand() % 10;                    //숫자를 다시 랜덤으로 재설정
        }while(temparr[index] == (int)wrongnum + 48);

        temparr[index] = (int)wrongnum + 48;            //랜덤으로 정해진 자리에 worngnum으로 대체
    }
    

    for(int i=0;i<5;i++)                //temp2로 temparr복사
    {
        temp2[i] = temparr[i];
    }
  

    Receiver(temp2);     //Receiver로 전달
    delete[] temp2;
}

void Receiver(const char* data)
{
    int checksum;       //checksum 계산
    checksum = (int(data[0])-48) + (int(data[1])-48) + (int(data[2])-48) + (int(data[3])-48);   
    checksum = checksum % 10;
    cout<<"Received Data:";
    for(int i=0;i<5;i++)
    {
        cout<<data[i];
    }
    cout<<endl;

    if(checksum == (int)data[4] - 48)
    {
        cout<<checksum<<"=="<<data[4];
        cout<<"    Error is not Occured!";
    }
    else if(checksum != data[4])
    {
        cout<<checksum<<"!="<<data[4];
        cout<<"    Error!";
    }

}