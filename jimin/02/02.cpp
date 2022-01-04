#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char arr[100];
    char save[100]={0,};
    cin.getline(arr, 100, '\n');
    int n=strlen(arr);
    char temp=arr[0];
    int sum=0,i,current=0;
    for(i=0; i<=n; i++){
        if(arr[i]==temp){
            sum++;
        }
        else if(sum!=1){
            save[current]=temp;
            current++;
            save[current]=sum+48;
            current++;
            temp=arr[i];
            sum=1;
        }
        else{
            save[current]=temp;
            current++;
            temp=arr[i];
            sum=1;
        }
    }
    cout<<save<<endl;
}