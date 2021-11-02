#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
    int maxi=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[maxi])
    maxi=l;
    if(r<n&&a[r]>a[maxi])
    maxi=r;
    if(maxi!=i){
        swap(a[i],a[maxi]);
        heapify(a,n,maxi);
    }
    
    
}

void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int i;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0; i<n; i++)
    cout << a[i] <<" ";
    cout<<endl<<"Sorted Array"<<endl;
    heapSort(a,n);
    for(int i=0; i<n; i++)
    cout << a[i] <<" ";
    return 0;
}