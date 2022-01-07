#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	int length,i,j,a;
	cout << "Array Size(0<N<11) : ";
	cin >> length;
	int* array = new int[length*length];
	for (i = 0; i < length * length; i++) {
		array[i] = dis(gen);
		for (j = 0; j < i; j++)
			if (array[i] == array[j])
				i--;
	}
	a = array[0];
	for (i = 0; i < length * length; i++) {
		for(j=0;j<length*length-1-i;j++){
			if (array[i] > array[i+j+1]) {
				a = array[i];
				array[i] = array[i+j+1];
				array[i+j+1] = a;
			}
		}
	}

	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++)
			printf("%3d",array[length*i+j]);
		cout << "\n";
	}
	delete[] array;
	return 0;
}