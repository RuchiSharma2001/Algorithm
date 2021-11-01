#include<bits/stdc++.h>
using namespace std;

void topoSort(int node,int vis[],stack<int> &st,vector<pair<int,int>> adj[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it.first])
            topoSort(it.first,vis,st,adj);
    }
    st.push(node);
}

void shortestPath(int src,int n,vector<pair<int,int>> adj[]){
    int vis[n]={0};
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,vis,st,adj);
        }
    }
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    dis[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dis[node]!=INT_MAX){
            for(auto it : adj[node]){
                if((dis[node]+it.second)<dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
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
    int u,v,w;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int src;
    cin>>src;
    shortestPath(src,n,adj);
    return 0;
}