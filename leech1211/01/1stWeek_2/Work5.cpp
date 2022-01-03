#include <iostream>
#include<cstdlib>       //Random number     rand(),srand()
#include<ctime>         //Random number time seed       time()
using namespace std;


void bubble(int** arr, int last, int ArrSize)      //배열,요소의 개수,Arrsize
{
    
    //int narr[last] = {0,};           //이전코드
    int *narr = new int[last]();       //1차원 배열 동적할당

    int k = 0;
    int temp;
    for(int i=0;i<ArrSize;i++)      //2차원배열을 
    {
        for(int j=0;j<ArrSize;j++)
        {
            narr[k] = arr[i][j];
            k++;
        }
    }

   

    for(int i=0;i<last;i++)         //bubble sort
    {
        for(int j=last;j > i;j--)
        {
            if(narr[j] < narr[j - 1] )
            {
                temp = narr[j - 1];
                narr[j - 1] = narr[j];
                narr[j] = temp;
            }
        }
    }

    
    k = 0;
    for(int i=0;i<ArrSize;i++)      //정렬후 출력
    {
        for(int j=0;j<ArrSize;j++)
        {
            arr[i][j] = narr[k];
            cout.width(5);  
            cout<<arr[i][j];
            k++;
        }
        cout<<endl;
    }

    delete[] narr;                  //1차원 배열 메모리 해제

}

int main()
{
    int ArrSize;        //배열크기
    int **Arr;          //배열 Arr 
    int Arrlength = 0;  //배열의 요소의 개수
    srand((unsigned int)time(NULL));    //seed값으로 현재시간 부여  
    cout << "Array Size(0<N<11) : "  ;
    cin >> ArrSize;
    Arrlength = ArrSize * ArrSize;

    Arr = new int*[ArrSize];        //동적할당
    for(int i=0 ; i < ArrSize; i++)     //각행마다 동적할당
    {
        Arr[i] = new int[ArrSize];  
        for(int j=0 ; j < ArrSize ; j++)
        {
            cout.width(5);                  //5만큼 띄어쓰기 후 출력
            Arr[i][j] = rand() % 100;       //배열의 요소에 접근하여 랜덤값으로 초기화
            cout << left << Arr[i][j] ;     //left 를 이용해 숫자먼저 출력 후 빈칸
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    bubble(Arr,Arrlength,ArrSize);                //정렬함수에 배열과 요소의 개수,ArrSize 전달

    for (int i = 0; i < ArrSize; i++)   //메모리해제 
    {
         delete [] Arr[i];              //각 행마다 해제
    }      
        
    delete [] Arr;                      //마지막행도 해제

}