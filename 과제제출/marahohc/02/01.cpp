#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

void Sender();
void Transmission_Process(const char* data);
void Receive(const char* data);

int main(void) {
	Sender();
	return 0;
}
void Sender() {
	char *data = new char[6];
	int sum = 0;
	cout << "Data : ";
	for (int i = 0; i < 4; i++) {
		cin >> data[i];
		sum = (sum + (data[i] - '0')) % 10;
	}
	data[4] = (char)sum+'0';
	cout << "Send Data:";
	for (int i = 0; i < 5; i++) {
		cout << data[i];
	}
	cout << endl;
	Transmission_Process(data);
	delete[] data;
}

void Transmission_Process(const char* data) {
	srand((int)time(NULL));
	char* rcidata = new char[6];
	int num1 = rand()%10;

	for (int i = 0; i < 5; i++) {
		rcidata[i] = data[i];
	}

	if (num1 == 0 || num1 == 1 || num1 == 2 || num1 == 3) {
		int num = rand() % 4;
		int isntnum = 0;
		do {
			isntnum = rand() % 10;
		} while (isntnum == data[num]);

		rcidata[num] = (char)isntnum + '0';
	}
	Receive(rcidata);
	delete[] rcidata;
}

void Receive(const char* data) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum = (sum + (data[i] - '0')) % 10;
	}
	if ((int)data[4]-'0' == sum) {
		cout << "Received Data:";
		for (int i = 0; i < 5; i++) {
			cout << data[i];
		}
		cout << endl << data[4] << "==" << sum << "    Error is not Occured!";
	}
	else if ((int)data[4]-'0' != sum) {
		cout << "Received Data:";
		for (int i = 0; i < 5; i++) {
			cout << data[i];
		}
		cout << endl << data[4] << "!=" << sum << "    Error!";
	}
}