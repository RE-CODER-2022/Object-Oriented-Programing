#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i,z=1;
	string x;
	getline(cin, x);
	for (i = 0; x[i]!=0; i++) {
		if (x[i] == x[i + 1])
			z++;
		else if (x[i] != x[i + 1]) {
			cout << x[i];
			if (z != 1)
				cout << z;
			z = 1;
		}
	}
	return 0;
}