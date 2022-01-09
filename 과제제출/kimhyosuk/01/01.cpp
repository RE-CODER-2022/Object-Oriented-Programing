#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

int main(void)
{
	int arr_len;
	int count = 0;
	char arr[1000];
	cin.getline(arr, 1000);
	arr_len = strlen(arr);
	for (int i = 0; i < arr_len; i++)
	{
		count++;
		if (arr[i] != arr[i + 1])
		{
			if (count == 1)
			{
				cout << arr[i];
			}
			else {
				cout << arr[i] << count;
			}
			count = 0;
		}
	}
	return 0;
}