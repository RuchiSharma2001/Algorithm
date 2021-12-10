#include<bits/stdc++.h>
using namespace std;
bool compare(pair<pair<int, int>, int> a,pair<pair<int, int>, int> b){
    return a.second>b.second;
}
int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    int valperwt,wt,val;
    vector<pair<pair<int,int>, int> > bag;
    for(int i=0;i<n;i++){
        cin>>wt>>val;
        valperwt=val/wt;
        bag.push_back({{wt,val},valperwt});
    }
    sort(bag.begin(),bag.end(),compare);
    int maxprofit=0;
    for(int i=0;i<n;i++){
        if(k>=bag[i].first.first){
            maxprofit+=bag[i].first.second;
            k=k-bag[i].first.first;
        }
        else{
            maxprofit+=bag[i].second*k;
            k=0;
            break;
        }
    }
    cout<<maxprofit;
}