#include<bits/stdc++.h>
bool comp(vector<int> a, vector<int> b){
    return a[2]>b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    int maxi=jobs[0][1];
    for(int i=1;i<n;i++){
        maxi=max(maxi, jobs[i][1]);
    }
    vector<int> slot(maxi+1,-1);
    int countJobs=0, profit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][1];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                countJobs++;
                profit+=jobs[i][2];
                break;
            }
        }
    }
    return {countJobs,profit};
}
