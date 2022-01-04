#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    char str[500];
    int cnt = 1;
    int i=0;
    cin.getline(str,500);
    while (str[i] != '\0') {

        if (str[i] == str[i + 1])
            cnt++;
        else{
            if (cnt == 1)
                cout << str[i];
            else {
                cout << str[i] << cnt;
                cnt = 1;
            }
        }
        i++;
    }
    cout << endl;
    return 0;
} 