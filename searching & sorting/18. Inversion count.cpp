DIVIDE AND CONQUER PROBLEM

typedef long long ll;
ll merge(ll arr[], ll lo, ll mid, ll hi){
    ll n1=mid-lo+1, n2=hi-mid;
    ll t1[n1], t2[n2];
    for(ll i=0;i<n1;i++){
        t1[i]=arr[lo+i];
    }
    for(ll i=0;i<n2;i++){
        t2[i] =  arr[mid+1+i];
    }
    
    ll ans=0;
    ll k=lo,i=0,j=0;
    while(i<n1 && j<n2){
        if(t1[i] <= t2[j]){
            arr[k++] = t1[i++];
        }
        else{
            ans+=(n1-i);
            arr[k++] = t2[j++];
        }
    }
    while(i<n1){
        arr[k++] = t1[i++];
    }
    while(j<n2){
        arr[k++] = t2[j++];
    }
    
    return ans;
}

ll inversionCountUtil(ll arr[], ll lo, ll hi){
    if(lo>=hi) return 0;
    ll mid = lo+(hi-lo)/2;
    ll ans=0;
    ans+=inversionCountUtil(arr,lo,mid);
    ans+=inversionCountUtil(arr,mid+1,hi);
    ans+=merge(arr,lo,mid,hi);
    return ans;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return inversionCountUtil(arr,0,N-1);
}
