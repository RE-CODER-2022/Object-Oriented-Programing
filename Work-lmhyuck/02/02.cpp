#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void checksum(int* data, int* datasum);
void errorcheck(int* datasum, int* redata);
void receiver(int* datasum, int* redata);
int num = 0;

int main()
{
    int* data, * datasum, * redata;
    data = new int[5];
    datasum = new int[6];
    redata = new int[6];
    cout << "Data : ";
    for (int i = 0; i < 4; i++)
        scanf("%1d", &data[i]);
    checksum(data, datasum);
    cout << "Send Data:";
    for (int i = 0; i < 5; i++)
        cout << datasum[i];
    errorcheck(datasum, redata);
    cout << "Received Data:";
    receiver(datasum, redata);
    delete[] data;
    delete[] datasum;
    delete[] redata;
    cout << endl;
    return 0;
}
//입력받은 데이터를 checksum
void checksum(int* data, int* datasum) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            datasum[4] = sum % 10;
            break;
        }
        datasum[i] = data[i];
        sum += data[i];
    }
}
//데이터 전송 간 오류 발생 체크
void errorcheck(int* datasum, int* redata) {
    srand((unsigned int)time(NULL));
    int n = 0;
    n = rand() & 10;
    num++;
    while (1) {
        int a = 0;
        a = rand() & 4;
        int b = 0;
        b = rand() & 10;
        for (int i = 0; i < 5; i++)
        {
            if (a == i)
            {
                if (b == datasum[i])
                {
                    continue;
                }
                else
                    redata[i] = b;
            }
            else
                redata[i] = datasum[i];
        }
        break;
    }
}
    else {
    for (int i = 0; i < 5; i++)
        redata[i] = datasum[i];
    }
    cout << endl;
}
//전송받은 데이터의 에러 발생 유무 판단
void receiver(int* datasum, int* redata) {
    if (num == 0) {
        for (int i = 0; i < 5; i++)
            cout << redata[i];
        cout << endl << redata[4] << "==" << redata[4];
        cout << "    Error is not Occured!";
    }
    else {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum = sum + redata[i];
        for (int i = 0; i < 5; i++)
            cout << redata[i];
        cout << endl << datasum[4] << "!=" << sum % 10;
        cout << "    Error!";
    }
}