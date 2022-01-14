#include<iostream>
#include<cstdlib>
using namespace std;
int data_sum;

void Sender(char* data, char* datasum);
void Transmission_Process(const char* datasum,char* error_data);
void Receiver(const char* datasum, char* error_data);
int main()
{
    char* data, *datasum, * error_data;
    data = new char[5];
    datasum = new char[6];
    error_data = new char[6];
    Sender(data,datasum);
    Transmission_Process(datasum,error_data);
    Receiver(datasum,error_data);
    delete[] data;
    delete[] datasum;
    delete[] error_data;
    return 0;
}

void Sender(char* data, char* datasum)
{
    cout<<"Data : ";
    cin >> data;
    for(int i = 0; i<4;i++)
    {
        data_sum += data[i] -'0';
    }
    data_sum = data_sum %10;
    for(int i = 0; i< 5; i++)
    {
        if(i < 4)
        {
            datasum[i] = data[i];
        }
        else{
            datasum[i] = data_sum + '0';
        }
    }
    cout << "send Data: ";
    for(int i =0; i< 5;i++)
    {
        cout << datasum[i];
    }
    cout << endl;
}

void Transmission_Process(const char* datasum, char* error_data)
{
    srand((unsigned int)time(NULL));
    int random_num = 0;
    random_num = rand() %10;
    if(random_num < 4 && random_num >=0)
    {
        while(1)
        {
            int random_num2 = rand() % 5;
            int random_num3 = rand() % 10;
            for(int i = 0; i<5;i++)
            {
                if(i == random_num2)
                {
                    if(random_num3 == datasum[i])
                    {
                        continue;
                    }
                    else{
                        error_data[i] = random_num3 + '0';
                    }
                }
                else{
                    error_data[i] = datasum[i];
                }
            }
            break;
        }
    }
    else{
        for(int i =0; i<5;i++)
        {
            error_data[i] = datasum[i];
        }
    }
}

void Receiver(const char* datasum, char* error_data)
{
    int error_data_sum = 0;
    for(int i = 0;i<4;i++)
    {
        error_data_sum += error_data[i] - '0';
    }
    error_data_sum = error_data_sum %10;
    cout << "Received Data:";
    if(error_data[4] != datasum[4])
    {
        for(int i = 0;i<5;i++)
        {
            cout << error_data[i];
        }
        cout << endl;
        cout << datasum[4] << "!=" << error_data[4] << "    ";
        cout << "Error!" << endl;
    }
    else if(error_data[0] !=datasum[0] ||error_data[1] !=datasum[1]||error_data[2] !=datasum[2]||error_data[3] !=datasum[3])
    {
        for(int i = 0;i<5;i++)
        {
            cout << error_data[i];
        }
        cout << endl;
        cout << datasum[4] << "!=" << error_data_sum << "    ";
        cout << "Error!" << endl;
    }
    else{
        for(int i = 0;i<5;i++)
        {
            cout << error_data[i];
        }
        cout << endl;
        cout << datasum[4] << "==" << error_data_sum << "    ";
        cout << "Error is not Occured!" << endl;
    }
}