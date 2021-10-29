#include<bits/stdc++.h>
using namespace std;

void storedfs(int node, vector<int> &vis,vector<int> adj[],vector<int> &dfs){
    dfs.push_back(node);
    vis[node]=1;
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            storedfs(*it,vis,adj,dfs);
        }
    }
}
vector<int> dfsOfGraph(int v, vector<int> adj[]){
    vector<int>dfs;
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            storedfs(i,vis,adj,dfs);
        }
    }
    return dfs;
}


int main(){
    int n,m;
    cin>>n>>m;
     int u,v;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
       
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dfs=dfsOfGraph(n, adj);
    for(int i=0;i<v;i++){
        cout<<dfs[i]<<" ";
    }
    return 0;
}