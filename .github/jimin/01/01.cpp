#include<iostream>
using namespace std;
void bubble(int *, int, int);

void sorting(int * arr,int n){
    for(int i=n-1; i>0; i--){
        bubble(arr,i,n);
    }
}

void bubble(int * arr, int c, int n ){
    int temp;
    for(int i=0; i<c; i++){
        if(arr[i]>arr[i+1]){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}

int main(){
    int n;

    int arr[11*11]={0,};
    cout<<"Array Size(0<N<11) : ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i*n+j];
        }
    }
    sorting(arr,n*n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i*n+j]<<'\t';
        }
        cout<<endl;
    }
}
