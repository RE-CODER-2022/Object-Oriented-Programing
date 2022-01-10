#include <iostream>

using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100, '\n');
    int length = 0;
    for (int i = 0; i < 100; i++) {
        if (str[i] != 0) length++;
        else break;
    }

    int num = 1, k = 0, numArr[100];
    char arr[100];
    for (int i = 0; i < length; i++) {
        if (i == length -1) {
            arr[k] = str[i];
            numArr[k] = 1;
        }
        for (int j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                num++;
                if (j == length - 1) {
                    arr[k] = str[i];
                    numArr[k] = num;
                    k += 1;
                    num = 1;
                    i = j;
                }
            } else {
                arr[k] = str[i];
                numArr[k] = num;
                k += 1;
                num = 1;
                i = j - 1;
                break;
            }
        }
    }
    int arrLength = 0;
    for (int i = 0; i < 100; i++) {
        if (numArr[i] != 0)
            arrLength++;
        else break;
    }
    for (int i = 0; i < arrLength; i++) {
        if (numArr[i] == 1)
            cout << arr[i];
        else
            cout << arr[i] << numArr[i];
    }
    return 0;
}