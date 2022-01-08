#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void sorting(int N, int length, int** sort_arr)
{
	int* temp_arr = new int[length]; 
	int k = 0;

	
	for (int i = 0; i < N; i++)     
	{
		for (int j = 0; j < N; j++)
		{
			temp_arr[k] = sort_arr[i][j];
			k++;
		}
	}


	int temp;

	for (int i = 0; i < length; i++)       
	{
		for (int j = length; j > i; j--)
		{
			if (temp_arr[j] < temp_arr[j - 1])
			{
				temp = temp_arr[j - 1];
				temp_arr[j - 1] = temp_arr[j];
				temp_arr[j] = temp;
			}
		}
	}


	int k = 0;

	for (int i = 0; i < N; i++)     
	{
		for (int j = 0; j < N; j++)
		{
			sort_arr[i][j] = temp_arr[k];
			cout << sort_arr[i][j] << "	";
			k++;
		}
		cout << endl;
	}

	delete[] temp_arr;            

	return;
}




int main(void)
{
	int N = 0;

	cout << "Array Size(0<N<11): ";
	cin >> N;
	int arr_length = N * N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	std::random_device rd; // 시드값을 얻기 위한 random_device 생성
	std::mt19937 mersenne(rd()); // random_device를 통해 난수 생성 엔진 초기화
	std::uniform_int_distribution<> range(1, 100); // 1부터 1000까지 균등하게 나타나는 난수열 생성을 위한 균등 분포 정의

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = range(mersenne);
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;

	sorting(N, arr_length, arr);

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}