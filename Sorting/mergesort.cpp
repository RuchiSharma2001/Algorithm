#include<iostream>
using namespace std;

void merge(int a[],int b,int m,int e){
    int i,j,k;
    int n1=m-b+1;
    int n2=e-m;
    int l[n1],r[n2];
    for(i=0;i<n1;i++){
        l[i]=a[b+i];
    }
    for(j=0;j<n2;j++){
            r[j]=a[m+1+j];
        }
    i=0;
    j=0;
    k=b;
    
    while(i<n1&&j<n2){
        if(l[i]<r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=r[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int l,int h){
    if(l<h){
        int m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main(){
    int n;
    cin>>n;
    int i,a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}