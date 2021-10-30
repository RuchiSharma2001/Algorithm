#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node,vector<int> adj[],int color[]){
    if(color[node]==-1)
    color[node]=1;
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(color[*it]==-1){
            color[*it]=1-color[node];
            if(!bipartiteDfs(*it,adj,color))
                return false;
        }
        else if(color[*it]==color[node]){
            return false;
        }
    }
    return true;
}

bool checkBipartite(int n,vector<int> adj[] ){
    int color[n];
    memset(color,-1,sizeof color);
    for(int i=0;i<n;i++){
        if(!bipartiteDfs(i,adj,color)){
            return false;
        }
    }
    return true;
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
    if(checkBipartite(n,adj)){
        cout<<"Bipartite Graph";
    }
    else{
        cout<<"Not a bipartite graph";
    }
    return 0;
}