#include<bits/stdc++.h>
using namespace std;
void shortestDistance(int n,vector<int> adj[],int src){
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    queue <int> q;
    dis[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if((dis[node]+1)<dis[*it]){
                dis[*it]=dis[node]+1;
                q.push(*it);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int u,v,i;
    vector<int> adj[n+1];
    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    shortestDistance(n,adj,src);
    return 0;
}