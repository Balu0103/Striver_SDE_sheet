class Solution {
    private:
        static bool comp( vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int second=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]< second) count++;
            else second=intervals[i][1];
        }
        return count;
    }
};
