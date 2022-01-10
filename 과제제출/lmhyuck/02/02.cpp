#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void sender(char* data, char* datasum);
void Transmission_Process(char* datasum, char* redata);
void Receiver(char* datasum, char* redata);
int num = 0;

int main()
{
    char* data, * datasum, * redata;
    data = new char[5];
    datasum = new char[6];
    redata = new char[6];
    sender(data, datasum);
    Transmission_Process(datasum, redata);
    Receiver(datasum, redata);
    delete[] data;
    delete[] datasum;
    delete[] redata;
    cout << endl;
    return 0;
}
//입력받은 데이터를 checksum
void sender(char* data, char* datasum) {
    int sum = 0;
    cout << "Data : ";
    cin >> data;
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            datasum[4] = (sum % 10) + 48;
            break;
        }
        datasum[i] = data[i];
        sum += data[i] - 48;
    }
    cout << "Send Data: ";
    for (int i = 0; i < 5; i++)
        cout << datasum[i];
}
//데이터 전송 간 오류 발생 체크
void Transmission_Process(char* datasum, char* redata) {
    srand((unsigned int)time(NULL));
    int n = 0;
    n = rand() & 10;
    if (n >= 0 && n < 4)
    {
        num++;
        while (1)
        {
            int a = 0;
            a = rand() & 5; //0~4까지
            int b = 0;
            b = rand() & 10;//0~9까지
            for (int i = 0; i < 5; i++)
            {
                if (a == i)
                {
                    if (b == datasum[i]-48)
                    {
                        continue;
                    }
                    else
                        redata[i] = b + 48;
                }
                else
                    redata[i] = datasum[i];
            }
            if (a == 4)
                num ++;
            break;
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
            redata[i] = datasum[i];
    }
    cout << endl;
}
//전송받은 데이터의 에러 발생 유무 판단
void Receiver(char* datasum, char* redata) {
    cout << "Received Data: ";
    if (num == 0) {
        for (int i = 0; i < 5; i++)
            cout << redata[i];
        cout << endl << redata[4] << "==" << redata[4];
        cout << "    Error is not Occured!";
    }
    else if (num == 2) {
        for (int i = 0; i < 5; i++)
            cout << redata[i];
        cout << endl << datasum[4] << "!=" << redata[4];
        cout << "    Error!";
    }
    else {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += redata[i] - 48;
        for (int i = 0; i < 5; i++)
            cout << redata[i];
        cout << endl << datasum[4] << "!=" << sum % 10;
        cout << "    Error!";
    }
}