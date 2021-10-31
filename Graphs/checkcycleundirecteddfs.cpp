#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int node,vector<int> adj[], int vis[],int dfsvis[]){
    vis[node]=1;
    dfsvis[node]=1;
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            if(isCyclic(*it,adj,vis,dfsvis))
                return true;
        }
        else if(dfsvis[*it]==1)
            return true;
    }
    dfsvis[node]=0;
    return false;
}

bool checkCycle(int n,vector<int> adj[]){
    int vis[n],dfsvis[n];
    memset(vis,0,sizeof vis);
    memset(dfsvis,0,sizeof dfsvis);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCyclic(i,adj,vis,dfsvis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    int u,v,i;
    vector<int> adj[n+1];
    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    if(checkCycle(n,adj)){
        cout<<"Cycle Present";
    }
    else{
        cout<<"Cycle not present";
    }
}