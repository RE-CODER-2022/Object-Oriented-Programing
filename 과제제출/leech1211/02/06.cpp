#include <iostream>
#include<cstdlib>       //Random number     rand(),srand()
#include<ctime>         //Random number time seed  
using namespace std;

void Sender();
int Transmission_Process(const char* data);
int Receiver(const char* data);


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
    
    input[4] = (char)checksum + 48;   
 
    cout<<"Send Data:"<<input<<endl;
    Transmission_Process(input);
    delete[] input;
   
}

void Transmission_Process(const char* data)
{
    int error;          //에러가 날 확률
    int wrongChecksum;  //잘못된 checksum 
    char temparr[5];   //const로 전달된 data를 다루기 위한 임시배열

    char* temp2 = new char[5];
    

    for(int i=0;i<5;i++)                //temparr로 data복사
    {
        temparr[i] = data[i];
    }
    srand((unsigned int)time(NULL));    //seed값으로 현재시간 부여  
    error = rand() % 10;        
    do                                  //checksum을 대체할 새로운 checksum을 랜덤으로 만들되, 기존의 checksum과 같지않게
    {
        wrongChecksum = rand() % 10;
    }while(wrongChecksum == (int)temparr[4] + 48);
    

    //cout<<"error: "<<error << endl;

    if(error <= 3)  //0~9 10개의 숫자중에 0,1,2,3 네개의 숫자에 해당되는 경우 즉 40%의 확률
    {
        temparr[4] = (int)wrongChecksum + 48;
    }
    //cout<<"wrongChecksum: "<< wrongChecksum <<endl;
    //cout<<"temparr: "<<endl;

    // for(int i=0;i<5;i++)     //temparr 확인
    // {
    //     cout<<temparr[i];
    // }
    // cout<<"temparr0: "<<temparr[0]<<endl;
    // cout<<"temparr1: "<<temparr[1]<<endl;
    // cout<<"temparr2: "<<temparr[2]<<endl;
    // cout<<"temparr3: "<<temparr[3]<<endl;
    // cout<<"temparr4: "<<temparr[4]<<endl;

    for(int i=0;i<5;i++)                //temp2로 temparr복사
    {
        temp2[i] = temparr[i];
    }
    //cout<<"temp2: "<<endl;
    // for(int i=0;i<5;i++)                //temp2로 temparr복사
    // {
    //     cout<<temp2[i]; 
    // }

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