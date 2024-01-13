class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int minCost=temp.first;
            int node=temp.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(wt+minCost < dist[adjNode]){
                    dist[adjNode]=minCost+wt;
                    pq.push({minCost+wt,adjNode});
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
};
