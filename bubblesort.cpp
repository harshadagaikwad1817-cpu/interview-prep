#include<iostream>
using namespace std;
void bubblesort(int array[], int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++) {
            if(array[j]>array[j+1]){
            swap(array[j],array[j+1]);
            }
        }
    }
    cout<<"array after sorting\n";
    for(int i=0;i<n;i++) {
        cout<<array[i]<<" ";
    }
}
int main() {
    int arr[]={4,1,5,2,3};
    int n=sizeof(arr) / sizeof(arr[0]); 
    cout<<"array before sorting\n";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    bubblesort(arr,n);
    return 0;
}