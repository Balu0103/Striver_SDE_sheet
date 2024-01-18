bool comp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n=start.size();
    vector<pair<int,int>> meetings;
    for(int i=0;i<n;i++){
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), comp);
    int ans=1;
    int limit=meetings[0].second;
    for(int i=1;i<n;i++){
        if(meetings[i].first>limit){
            ans++;
            limit=meetings[i].second;
        }
    }
    return ans;
}
