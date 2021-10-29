#include<bits/stdc++.h>
using namespace std;

bool checkforcycle(int s,int v,vector<int> adj[],vector<int>& visited){
    queue<pair<int,int> > q;
    visited[s]=true;
    q.push({s,-1});
    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                q.push({*it,node});
            }
            else if(par!=*it)
                return true;
        }
    }
    return false;
}

bool iscycle(int v,vector<int>adj[]){
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            if(checkforcycle(i,v,adj,vis))
                return true;
        }
    }
    return false;
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
    if(iscycle(n,adj)){
        cout<<"Cycle is present.";
    }
    else{
        cout<<"Cycle is not present.";
    }
    return 0;
}