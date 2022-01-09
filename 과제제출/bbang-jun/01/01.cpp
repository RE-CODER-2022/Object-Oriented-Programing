#include <iostream>
using namespace std; 

int main(void)
{
	int i = 0;
	char input[1000];
	int sum = 0;

	// cin.getline을 통한 입력(cin으로 받으면 버퍼에 의해 스페이스 이후의 입력 내용이 정상적으로 반영 x)
	cin.getline(input, sizeof(input));

	cout << input[0];

	// null을 만날 때까지(끝까지)
	while (input[i]!='\0')
	{
		if (input[i] == input[i + 1]) // 같은 문자가 연속으로 올 시에 1씩 +
		{
			sum++;
		}
		else // 다른 문자가 오는 경우
		{
			cout << sum+1 << input[i+1];  
			sum = 0;
		}
		i++;
	}

	return 0;
}