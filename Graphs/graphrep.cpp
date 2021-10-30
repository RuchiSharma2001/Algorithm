#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    //int adj[n-1][n-1];
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //using adjandency matrix
        //adj[u][v]=1;
        //adj[v][u]=1;
        //using adjandency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}