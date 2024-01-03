class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int> (n,1e9));
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) matrix[i][i]=0;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][via]!=1e9 && matrix[via][j]!=1e9){
                        matrix[i][j]=min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                    }
                }
            }
        }
        int cntCity=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold) count++;
            }
            if(count<=cntCity){
                cntCity=count;
                city=i;
            }
        }
        return city;   
    }
};
