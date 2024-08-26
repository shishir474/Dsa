

#include<bits/stdc++.h>
using namespace std;


const int n=1e8;
vector<bool> primes(n+1, true);

int32_t main()
{
   
    primes[0]=primes[1]=false;
    for(int i=2;i<=sqrt(n);i++){
        if(primes[i]){ // mark all the prime multiples of i as false
            for(int j=i*i;j<=n;j+=i){
                primes[j]=false;
            }
        }
    }



    int cnt=0;
    for(int i=2;i<primes.size();i++){
        if(primes[i]){
            cnt++;
            if(cnt%100 == 1){
                cout<<i<<endl;
            }
        }
    }


}
