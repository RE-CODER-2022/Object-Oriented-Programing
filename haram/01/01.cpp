#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void bubbleSort(int arr[], int last);
void bubbleUp(int arr[], int i, int last);

int main(void) {
    srand((int)time(NULL));
    int num = 0;
    int enter = 0;
    cout << "Array Size(0<N<11) : ";
    cin >> num;
    enter = num;
    num *= num;
    int* arr = new int[num];
    for (int i = 0; i < num; i++) {
        int f = 0;
        while (1) {
            int check = 0;
            f = ((int)rand() % 100);
            for (int j = 0; j < num; j++) {
                if (f != arr[j])continue;
                else if (f == arr[j]) {
                    check++;
                    break;
                }
            }
            if (check == 0) {
                arr[i] = f;
                break;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        if (i % enter == 0 && i != 0)
            cout << endl;
        cout.setf(ios::left);
        cout << setfill(' ') << setw(4) << arr[i];
    }
    cout << endl;
    bubbleSort(arr, num - 1);
    for (int i = 0; i < num; i++) {
        if (i % enter == 0)
            cout << endl;
        cout.setf(ios::left);
        cout << setfill(' ') << setw(8) << arr[i];
    }
    cout << endl;
}

void bubbleSort(int arr[], int last) {
    for (int i = 0; i < last; i++)
        bubbleUp(arr, i, last);
    return;
}

void bubbleUp(int arr[], int i, int last) {
    for (int j = last; j > i; j--) {
        if (arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
    return;
}