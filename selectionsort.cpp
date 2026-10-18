#include<iostream>
using namespace std;
void selectionsort(int array[], int n) {
    for(int i=0;i<n-1;i++){
        int smallindex=i;
        for(int j=i+1;j<n;j++) {                  
            if(array[j]<array[smallindex]){
            smallindex=j;
            }
        }
         swap(array[i],array[smallindex]);
    }
    cout<<"array after sorting\n";
    for(int i=0;i<n;i++) {
        cout<<array[i]<<" ";
    }
}
int main() {
    int arr[]={8,1,4,2,10};
    int n=sizeof(arr) / sizeof(arr[0]); 
    cout<<"array before sorting\n";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    selectionsort(arr,n);
    return 0;
}