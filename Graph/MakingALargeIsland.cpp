class DisJointSet{
    public:
        vector<int> parent, size;
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
            if(ultParent_u == ultParent_v) return;
            if(size[ultParent_u] > size[ultParent_v]){
                parent[ultParent_v]=ultParent_u;
                size[ultParent_u]+=size[ultParent_v];
            }
            else{
                parent[ultParent_u]=ultParent_v;
                size[ultParent_v]+=size[ultParent_u];
            }
        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisJointSet ds(n * n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int node=row*n+col;
                        int adjNode=nrow*n+ncol;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                set<int> st;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        //int value=ds.findUltParent(nrow*n+ncol);
                        st.insert(ds.findUltParent(nrow*n+ncol));
                    }
                }
                int sum=0;
                for(auto it:st){
                    sum+=ds.size[it];
                }
                ans=max(ans, sum+1);
            }
        }
        ans=max(ans, ds.size[ds.findUltParent(0)]);
        return ans;
    }
};
