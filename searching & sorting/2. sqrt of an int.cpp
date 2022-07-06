sample input/output
16 -> 4
20-> 4

int ans;
int lo=1,hi=N;
while(lo<=hi){
    int mid=(lo+hi)/2;
    if (mid*mid > N) hi=mid-1;
    else{
        ans = mid;
        lo = mid+1;
    }
}

return ans;