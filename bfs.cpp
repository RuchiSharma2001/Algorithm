#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int v, vector<int> adj[]){
    vector<int>bfs;
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                vector<int> :: iterator it;
               for(it=adj[node].begin();it!=adj[node].end();it++){
                    if(!vis[*it]){
                        q.push(*it);
                        vis[*it]=1;
                    }
                }
            }
        }
    }
    return bfs;
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
    vector<int>bfs=bfsOfGraph(n, adj);
    for(int i=0;i<n;i++){
        cout<<bfs[i]<<" ";
    }
    return 0;
}