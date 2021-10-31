#include<bits/stdc++.h>
using namespace std;

void topological(int node,stack<int> &st,vector<int> &vis, vector<int> adj[]){
    vis[node]=1;
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            topological(*it,st,vis,adj);
        }
    }
    st.push(node);
}

vector<int> toposort(int n,vector<int> adj[]){
    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            topological(i,st,vis,adj);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
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
    vector<int> topo =toposort(n,adj);
    for(i=0;i<n;i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}