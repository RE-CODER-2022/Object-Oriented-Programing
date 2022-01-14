#include <iostream>
#include <random>

using namespace std;

void Sender(void);
void Transmission_Process(const char* data);
void Receiver(const char* data);

int main()
{
	Sender();
	return 0;
}
void Sender(void) {
	int sum = 0;
	char arr[5];
	cout << "Data : ";
	cin >> arr;
	for (int i = 0; i < 4; i++)
		sum += arr[i];
	sum -= 48 * 4;
	sum = sum - (sum / 10) * 10 + 48;
	arr[4] = sum;
	cout << "Send Data : ";
	for (int i = 0; i < 5; i++)
		cout << arr[i];
	Transmission_Process(arr);
}
void Transmission_Process(const char* data) {
	int a, b;
	char arr[5];
	for (int i = 0; i < 5; i++)
		arr[i] = data[i];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 4);
	a = dis(gen);
	uniform_int_distribution<> dist(0, 9);

	if (dist(gen) < 4) {
		while (1) {
			b = dist(gen);
			if (arr[a] != b) {
				arr[a] = b+48;
				break;
			}
		}
	}
	Receiver(arr);
}
void Receiver(const char* data) {
	cout << endl<<"Received Data : ";
	int num[5],sum=0;
	for (int i = 0; i < 5; i++) {
		num[i] = data[i] - 48;
		cout << num[i];
	}
	
    for (int i = 0; i < 4; i++)
		sum += num[i];
	sum = sum - (sum / 10) * 10;
	if (sum == num[4])
		cout << endl<< num[4] <<"=="<<sum<<"  Error is not Occured!"<<endl;
	else
		cout << endl << num[4] << "!=" << sum << "  Error!" << endl;
}