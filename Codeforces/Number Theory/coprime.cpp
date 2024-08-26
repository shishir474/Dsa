#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define endl            "\n"
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i,n)       for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int32_t main()
{   
    initcode();

    // n <= 1e5. SO IT LOOKS LIKE o(n^2) IS NOT POSSIBLE HERE. OTHERWISE BRUTE FORCE WOULD BE TO CHECK EVERY PAIR. 
    // BUT WE HAVE ONLY 1000 DISTINCT VALUES, SO FOR EACH DISTINCT VALUE IF WE STORE THE LARGEST INDEX IT IS PRESENT AT, THEN WE CAN BRUTE FORCE ALL THOSE DISTINCT VALUES AND FIND MAX I+J FOR WHICH ARR[I] AND ARR[J] ARE COPRIME
    
    w(t){
        int n; cin>>n;
        int arr[n];
        forn(i,n) cin>>arr[i];
        map<int,int> mp;
        forn(i,n){
            mp[arr[i]] = i+1;
        }

        // since there are only 1000 distinct values, store the largest index of every no
        // and then brute force every pair 
        vector<int> v;
        for(auto i: mp){
             v.pb(i.first);
        }

        // for(auto i: v){
        //     cout<<i<<endl;
        // }


        int ans=-1;

        for(int i=0;i<v.size();i++){
            for(int j=i;j<v.size();j++){
                // cout<<v[i]<<" "<<v[j]<<endl;
                // cout<<mp[v[i]]<<" "<<mp[v[j]]<<endl;
                if(gcd(v[i],v[j])==1){ // check if v[i],v[j] are    coprime
                    ans = max(ans, mp[v[i]] + mp[v[j]]);
                }  
            }
         }

         cout<<ans<<endl;





        
    }
}