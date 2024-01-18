int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    int i=1,j=0;
    int plat_needed=1, result=1;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            plat_needed++;
            i++;
        }
        else if(at[i]>dt[j]){
            plat_needed--;
            j++;
        }
        if(plat_needed>result) result=plat_needed;
    }
    return result;
}
