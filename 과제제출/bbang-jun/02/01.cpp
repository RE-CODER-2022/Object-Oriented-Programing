#include <iostream>
#include <random>
using namespace std;

void Sender();
void Transmission_Process(const char* data);
void Receiver(const char* data);

void Sender()
{
	char send[5];
	int sum = 0;
	char checksum;

	cin >> send;

	cout << "Data: ";
	for (int i = 0; i < 6; i++)
		cout << send[i];

	// 배열 send가 char형이므로 아스키 코드이기 때문에 문자 '0'을 빼고 int형 변수 sum에 저장
	for (int i = 0; i < 4; i++)
		sum+=send[i] - '0';

	if (sum > 9)
		sum%=10;

	// sum이 in형 변수이기 때문에 문자 '0'을 더함으로써 아스키 코드로 만들어 char형 변수 checksum에 저장
	checksum = sum + '0';

	send[4] = checksum;

	cout << endl << "Send Data: ";
	for (int i = 0; i < 5; i++)
		cout << send[i];

	// 배열 send를 인자로
	Transmission_Process(send);
}

void Transmission_Process(const char* data)
{
	char transmission[5];
	random_device rd;
	mt19937 mersenne(rd());

	// 매개변수로 받은 data가 const이므로 변경할 수 없기에 transmission이라는 배열을 만들어 저장
	for (int i = 0; i < 5; i++)
		transmission[i] = data[i];

	uniform_int_distribution<> position_range(0, 4);

	// 배열의 위치를 0부터 4까지 랜덤 숫자 생성
	int position = position_range(mersenne);
	
	uniform_int_distribution<> random_range(0, 9);

	// 0부터 9까지 랜덤 숫자 생성
	int random = random_range(mersenne);

	// 40%의 확률을 생성하기 위해 0~9까지 10개 중 0~3 4개까지 제어문
	if (random < 4)
	{
		while (transmission[position] == random + '0')
		{
			transmission[position] = random_range(mersenne) + '0';
		}
	}
	else
		transmission[position] = random + '0';
	cout << endl;

	Receiver(transmission);
}

void Receiver(const char* data)
{
	char receive[5];

	cout << "Received Data: ";

	for (int i = 0; i < 5; i++)
		receive[i] = data[i];

	for(int i=0; i<5; i++)
		cout<<receive[i];
	cout << endl;

	int hap = 0;

	for (int i = 0; i < 4; i++)
		hap += receive[i]-'0';

	if (hap > 9)
		hap %= 10;

	if (receive[4] != hap + '0')
		cout << receive[4] << "!=" << hap << "	" << "Error!";
	else
		cout << receive[4] << "==" << hap << "	" << "Error is not Occured!";

	cout << endl;

}

int main(void)
{
	Sender();

	return 0;
}