#include<bits/stdc++.h>

using namespace std;

bool checkForCycle(int node,int parent,vector<int> &vis,vector<int> adj[]){
    vis[node]=1;
    vector<int>:: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(vis[*it]==0){
            if(checkForCycle(*it,node,vis,adj))
                return true;
        }
        else if(*it!=parent)
            return true;
    }
    return false;
}

bool isCycle(int n,vector<int> adj[]){
    vector<int> vis(n-1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkForCycle(i,-1,vis,adj))
                return true;
        }
    }
    return false;
}

int main(){
    int n,m,i,u,v;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(n,adj)){
        cout<<"Cycle is present";
    }
    else
        cout<<"Cycle not present";
    return 0;
}