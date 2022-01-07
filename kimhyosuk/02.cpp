#include<iostream>
#include<random>
#include<iomanip>
using namespace std;

int main(void)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,99);
    int N;
    int temp;
    int array[10][10];
    int array_bubble[100]={0};
    cout<<"Array Size(0<N<11) : ";
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            array[i][j] = dis(gen);
        }
    }
    for(int i = 0;i<N-1;i++)
    {
        for(int j = 0;j<N-1;j++)
        {
            cout<<setw(2)<<array[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0; j<N;j++)
        {
            array_bubble[i*N+j] = array[i][j];
        }
    }
    for(int i = 0 ;i<N*N-1;i++)
    {
        for(int j = 0;j<N*N-1-i;j++)
        {
            if(array_bubble[j]>array_bubble[j+1])
            {
                temp = array_bubble[j];
                array_bubble[j] = array_bubble[j+1];
                array_bubble[j+1] = temp;
            }
        }
    }
    for(int i = 0;i<N;i++)
    {
        for(int j =0;j<N;j++)
        {
            array[i][j] = array_bubble[i*N +j];
        }
    }
    for(int i =0;i<N;i++)
    {
        for(int j =0;j<N;j++)
        {
            cout<<setw(2)<<array[i][j]<<"    ";
        }
        cout<<endl;
    }
    return 0;
}