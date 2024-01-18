int assignCookie(vector<int> &greed, vector<int> &size) {
	sort(greed.begin(), greed.end());
	sort(size.begin(), size.end());
	int count=0;
	int n=greed.size();
	int m=size.size();
	int i=0,j=0;
	while(i<n && j<m){
		if(size[j]>=greed[i]){
			count++;
			i++;
			j++;
		}
		else j++;
	}
	return count;
}
