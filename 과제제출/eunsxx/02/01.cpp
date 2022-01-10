#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void Sender(char *data) {
    int sum = data[0] + data[1] + data[2] + data[3] - ('0' * 4); // 각 자리를 더한 값을 int 형으로 변환
    sum %= 10; // sum의 1의 자리 수
    data[4] = sum + '0'; // char 형으로 변환
}

string Transmission_Process(const char *data) {
    char transData[6];
    srand(time(NULL)); // 시드 설정
    int rd = rand() % 5; // 0~4의 랜덤 값을 rd에 저장
    for (int i = 0; i < 5; i++)
        transData[i] = data[i];
    transData[5] = '\0';
    switch (rd) { // rd 는 몇번째 자리인지 결정
        case 0: // first digit -> 값 랜덤(0~9)으로 변경
            transData[0] = (char) (rand() % 10) + '0';
            break;
        case 1: // second digit -> 값 랜덤(0~9)으로 변경
            transData[1] = (char) (rand() % 10) + '0';
            break;
        case 2: // third digit -> 값 랜덤(0~9)으로 변경
            transData[2] = (char) (rand() % 10) + '0';
            break;
        case 3: // forth digit -> 값 랜덤(0~9)으로 변경
            transData[3] = (char) (rand() % 10) + '0';
            break;
        case 4: // fifth digit -> 값 랜덤(0~9)으로 변경
            transData[4] = (char) (rand() % 10) + '0';
            break;
    }
    string str(transData); // char 형의 transData를 string형으로 변환
    return str;
}

int Receiver(const char *data) {
    int sum = data[0] + data[1] + data[2] + data[3] - ('0' * 4); // int 형으로 변환
    sum %= 10;

    return sum; // sum 값 리턴
}

int main() {
    char data[6];
    cout << "Data : ";
    cin >> data;
    Sender(data);
    cout << "Send Data : " << data << endl; // Send Data 출력
    string tData = Transmission_Process(data);
    char rData[6];
    strcpy(rData,tData.c_str()); // string 형의 tData -> char 형의 rData로 변환
    cout << "Received Data : " << rData << endl;
    int a = Receiver(data); // Send Data의 checksum 값
    int b = Receiver(rData); // Received Data의 Checksum 값
    if (a == b) // Checksum 값이 서로 같을 때
        cout << a <<"=="<<b<<"\t"<<"Error is not Occurred!" << endl;
    else
        cout << a <<"!="<<b<<"\t"<<"Error!"<<endl;
    return 0;
}