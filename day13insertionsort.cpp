#include<iostream>
using namespace std;
void insertionsort(int arr[],int n) {
    for(int i=1;i<n;i++) {
        int current=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>current) {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }
}
void printarray(int arr[],int n) {
    for(int i=0;i<n;i++) {
      cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[]={4,1,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    printarray(arr,n);
    return 0;
}