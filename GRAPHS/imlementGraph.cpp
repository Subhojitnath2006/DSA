#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter no of vertices and edges : ";
    cin>>n>>m;
    //Undirected graph
    //Matrix form
    //space complexity O(n^2)
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    //Adjacency List
    //space complexity O(2e) where e is the no of edges
    vector<int> adjL[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    //Directed graph
    //Matrix form
    //space complexity O(n^2)
    int adjD[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adjD[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // as u---->v u is directed towards v
        adjD[u][v]=1;  
    }
    //Adjacency List
    //space complexity O(e) where e is the no of edges
    vector<int> adjDL[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // as u---->v u is directed towards v
        adjDL[u].push_back(v);  
    }

}