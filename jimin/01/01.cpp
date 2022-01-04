#include<iostream>
#include<random>
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
    int n,c;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,99);
    cout<<"Array Size(0<N<11) : ";
    cin>>n;
    int * arr = new int[n*n];
    int k=0;
    while(k!=n*n){
        arr[k]=dis(gen);
        for(int i=0; i<k; i++){
            if(arr[k]==arr[i])
                k--;
        }
        k++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i*n+j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    sorting(arr,n*n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i*n+j]<<'\t';
        }
        cout<<endl;
    }
    delete [] arr;
}
