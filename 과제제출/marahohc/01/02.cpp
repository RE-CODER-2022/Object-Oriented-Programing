#include <iostream>
#include <string>
using namespace std;

int main(void) {
    char arr[100];
    int count = 1;
    int i=0;
    cin.getline(arr,100);
    while (arr[i] != '\0') {

        if (arr[i] == arr[i + 1])
            count++;
        else if (arr[i] != arr[i + 1]) {
            if (count == 1)
                cout << arr[i];
            else {
                cout << arr[i] << count;
                count = 1;
            }
        }
        i++;
    }
    cout << endl;
    return 0;
}