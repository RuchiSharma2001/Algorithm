#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n,vector<int> adj[]){
    vector<int> topo;
    vector<int> indegree(n,0);
    int i;
    vector<int> :: iterator it;
    for(i=0;i<n;i++){
        for(it=adj[i].begin();it!=adj[i].end();it++){
            indegree[*it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int node= q.front();
        q.pop();
        topo.push_back(node);
        for(it=adj[node].begin();it!=adj[node].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }
    }
    return topo;
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
    vector<int> topo=topoSort(n,adj);
    for(i=0;i<n;i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}