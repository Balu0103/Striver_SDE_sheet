class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int visited[n][m];
        int countFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else visited[i][j]=0;
                if(grid[i][j]==1) countFresh++;
            }
        }
        //if(countFresh==0) return 0;
        //if(q.empty()) return -1;
        int time=0; //answer time
        int cnt=0;
        //delta row
        int dRow[]={-1,0,1,0};
        //delta col
        int dCol[]={0,1,0,-1};
        while(!q.empty()){
            auto temp=q.front();
            int r=temp.first.first;
            int c=temp.first.second;
            int t=temp.second;
            q.pop();
            time=max(time,t);
            for(int k=0;k<4;k++){
                int nRow=r+dRow[k];
                int nCol=c+dCol[k];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    visited[nRow][nCol]=2;
                    cnt++;
                }
            }
        }
        return cnt==countFresh?time:-1;
    }
};
