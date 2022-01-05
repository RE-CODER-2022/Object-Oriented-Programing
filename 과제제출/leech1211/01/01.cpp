#include <iostream>
using namespace std;

int main()
{
    string input;
    int count = 0;   //연속된 문자의 길이
    getline(cin,input);

    for(int i=0;i<input.length();i++)
    {
        if(input[i] == input[i+1])      //다음문자와 같은경우
        {
            count++;
        }
        else if(input[i] != input[i+1]) //다음문자와 같지않은경우
        {
            cout << input[i] << count+1;
            count = 0;
        }
        else                            //문자열이 끝난경우
        {
            count = 0;
        }        
    }
}