#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    //find the ultimate parent
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    //check wheather 2 nodes belongs from same component or not
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        //if both are already in same component
        if(ulp_u==ulp_v){
            return;
        }
        //if both are not in same component
        //rank of  up of v is greater than that of up of u
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        //rank of  up of u is greater than that of up of v
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        //both have same rank
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        //if both are already in same component
        if(ulp_u==ulp_v){
            return;
        }
        //if both are not in same component
        //size of  up of v is greater than that of up of u
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        //size of  up of u is greater than that of up of v
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int findMstWeght(int v,vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            edges.push_back({it[1],{i,it[0]}});
        }
    
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(v);
    int ans=0;
    for(auto it:edges){
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            ans+=w;
            ds.unionByRank(u,v);
        }
    }
    return ans;

}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj[v];
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cout<<findMstWeght(v,adj);
}