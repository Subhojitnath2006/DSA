#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    //Undirected weighted graph
    //Adjacency matrix
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;
    }
    //Adjacency list
    vector<pair<int,int>> adjWL[n];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adjWL[u].push_back({v,wt});
        adjWL[v].push_back({u,wt});
    }

    
    return 0;
}