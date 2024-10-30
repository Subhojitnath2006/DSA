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
int maxRemove(vector<vector<int>>& stones, int n) {
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_set<int> st;
    
    for (auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        st.insert(nodeRow);
        st.insert(nodeCol);
    }
    
    int cnt = 0;
    for (auto it : st) {
        if (ds.findUPar(it) == it) cnt++;
    }
    
    return n - cnt;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> stones(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>stones[i][0]>>stones[i][1];
    }
    cout<<maxRemove(stones,n);
    return 0;
}