#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int>> g[n+1];
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    cin>>source;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> disto(n+1,INT_MAX);
    disto[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        vector<pair<int,int>>::iterator it;
        for(it =g[prev].begin();it!=g[prev].end();it++){
            int next=it->first;
            int nextdist=it->second;
            if(disto[next]>disto[prev]+nextdist){
                disto[next]=disto[prev]+nextdist;
                pq.push(make_pair(disto[next],next));
            }
        }
    }
    cout<<"The distance from source "<<source<<" are : \n";
    for(int i=1;i<=n;i++){
        cout<<disto[i]<<" \n";
    }
    return 0;
}