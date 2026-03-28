#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int timer = 0;
    void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>&mark,vector<vector<int>>&adj){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto &it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node],low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child > 1 && parent == -1) mark[node] = 1;
    }
    public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(V,0);
        int tin[V];
        int low[V];
        vector<int>mark(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges(E,vector<int>(2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    Solution ob;
    vector<int>ans=ob.articulationPoints(V,edges);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;

}