#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
    int i,j;
    for(i=1;i<n;i++){
        j=i-1;
        int key=arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n); 
    cout << "Sorted array: \n"; 
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}