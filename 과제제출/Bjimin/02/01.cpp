#include<iostream>
#include<random>
using namespace std;

void Sender();
void Transmission_Process(char *);
void Receiver(char *);


int main(){
    Sender();
}


void Sender(){ //4자리 수 입력받고, checksum덧붙이기
    char * arr = new char[6];
    int checksum=0;

    cout<<"Data : "; cin>>arr;

    for(int i=0; i<4; i++)
        checksum+=arr[i]-48;
    checksum=checksum%10;
    arr[4]=checksum+48; 
    arr[5]='\0';

    cout<<"Send Data:"<<arr<<endl;

    Transmission_Process(arr);
}


void Transmission_Process(char * arrpchecksum){ //40퍼센트 확률로 오류 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,4);
    uniform_int_distribution<int> dist(0,9);
    int m=dis(gen); //랜덤으로 5자리중 하나 선택
    int n=arrpchecksum[m]-48;
    int r=dist(gen);
    while(n==r)
        r=dist(gen);

    switch(dist(gen)){
        case 0: case 1: case 2: case 3: arrpchecksum[m]=r+48; break; //40퍼센트로 배열의 위치 중 하나에 기존과 다른 숫자(위 while에서 생성함) 입력
        default: break;
    }
    
    Receiver(arrpchecksum);
}


void Receiver(char * array){ //Tr_P에서 받은 배열의 checksum이 올바른지 확인, error 출력
    cout<<"Received Data:"<<array<<endl;

    int checksum=0;
    for(int i=0; i<4; i++)
        checksum+=array[i]-48; //문자 -> 숫자로 변환
    checksum=checksum%10;

    if(checksum==array[4]-48){ //array[4] 문자 -> 숫자로 변환해서 숫자끼리 비교
        cout<<checksum<<"=="<<array[4];
        cout<<"    Error is not Occured!"<<endl;
    }
    else{
        cout<<checksum<<"!="<<array[4];
        cout<<"    Error!"<<endl;
    }
    delete [] array;
} 
