#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare (pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}
int main(){
    vector<pair<int,int> > job;
    int n,profit,deadline;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>profit>>deadline;
        job.push_back(make_pair(profit,deadline));
    }
    sort(job.begin(),job.end(),compare);
    int maxendtime=0;
    for(int i=0;i<n;i++){
        if(job[i].second>maxendtime)
            maxendtime=job[i].second;
    }
    int fill[maxendtime];
    int count=0,maxprofit=0;
    for(int i=0;i<maxendtime;i++){
        fill[i]=-1;
    }
    for(int i=0;i<n;i++){
        int j=job[i].second-1;
        while(j>=0&&fill[j]!=-1){
            j--;
        }
        if(j>=0 && fill[j]==-1){
            cout<<"Profit is "<<job[i].first<<" deadline is "<<job[i].second<<endl;
            fill[j]=i;
            count++;
            maxprofit+=job[i].first;
        }
    }
    cout<<"Total activities "<<count<<"\nProfit "<<maxprofit<<endl;
    return 0;
}