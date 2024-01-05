#include<bits/stdc++.h>
class DisJointSet{
    vector<int> parent,size;
    public:
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUltParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUltParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ultParent_u=findUltParent(u);
            int ultParent_v=findUltParent(v);
            if(size[ultParent_u] > size[ultParent_v]){
                size[ultParent_u]+=size[ultParent_v];
                parent[ultParent_v]=ultParent_u;
            }
            else{
                parent[ultParent_u]=ultParent_v;
                size[ultParent_v]+=size[ultParent_u];
            }
        }
};
vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    DisJointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<int> ans;
    int count=0;
    for(auto it:queries){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1){
            ans.push_back(count);
            continue;
        }
        vis[row][col]=1;
        count++;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(vis[nrow][ncol]==1){
                    int node=row*m+col;
                    int adjNode=nrow*m+ncol;
                    if(ds.findUltParent(node)!=ds.findUltParent(adjNode)){
                        count--;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans;

}
