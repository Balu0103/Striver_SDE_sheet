#include<bits/stdc++.h>
int networkDelayTime(vector<vector<int>> &edges, int n, int k)
{
    vector<pair<int,int>> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    dist[k]=0;
    pq.push({0,k});
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int minCost=temp.first;
        int node=temp.second;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int eWeight=it.second;
            if(minCost+eWeight<dist[adjNode]){
                dist[adjNode]=minCost+eWeight;
                pq.push({minCost+eWeight,adjNode});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}
