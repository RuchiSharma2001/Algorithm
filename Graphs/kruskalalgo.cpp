#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};



int findpar(int u, vector<int> &parent){
    if (u== parent[u])
    return u;
    return findpar(parent[u],parent);
}

void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    vector<int> parent(n+1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<int> rank(n+1,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it: edges){
        if(findpar(it.v,parent)!=findpar(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    
    cout<<cost<<endl;
    for(auto it: mst){
        cout<<it.first<<"----"<<it.second<<endl;
    }
    return 0;
}