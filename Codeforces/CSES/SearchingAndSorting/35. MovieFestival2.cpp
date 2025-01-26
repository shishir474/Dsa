#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update>; // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets

#define int             long long int
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
#define forn(i,n)      for(int i=0;i<n;++i)
#define fore(i, l, r)   for(int i = l; i <= r; ++i)
#define all(v)          v.begin(), v.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode(){
    FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("cpp/input.txt", "r", stdin);
    // freopen("cpp/output.txt", "w", stdout);
    // #endif // ONLINE_JUDGE
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

int modularBinaryExponentitation(int base, int exponent){
    if(exponent==0) return 1;
    int val = modularBinaryExponentitation(base, exponent/2);
    if(exponent%2)
        return ((val*val)%mod*base)%mod;
    else    
        return (val*val)%mod;
}

struct cmp{
    bool operator()(const pii& p1, const pii& p2){
        return p1.second < p2.second;  
    }
};


// The movie1.endTime <= movie2.startTime -> This is allowed in this problem
// Why s.upper_bound({startTime, INT_MAX}) & why not s.upper_bound({start_time, 0});
signed main(){
    initcode();
    int n,k; cin>>n>>k;
    vector<pii> movies;
    forn(i,n){
        int start, end; cin>>start>>end;
        movies.pb({start,end});
    }
    // now sort the movies on end time: so that we can watch max no of movies
    sort(all(movies), cmp());
    // forn(i,n){
    //     cout<<movies[i].first<<" "<<movies[i].second<<endl;
    // }
    // cout<<endl;
    
    int bad_movie_cnt = 0;
    set<pii> s; // <endtime, index> set's max size will be k i.e s.size() <= k
    forn(i,n){
        int startTime = movies[i].first;
        int endTime = movies[i].second;
        if(s.size() < k){
            // any one of the k person can watch this movie
            s.insert({endTime, i});
        }
        else{ 
            // cout<<startTime<<" "<<endTime<<endl;
            // but if the set size is already k, then we will have to find a person who has already completed his movie before the current's movie start
            auto it = s.upper_bound({startTime, INT_MAX}); // if a movie ends at time t and other movie starts at time t -> then we can watch the other movie that's why the upper bound

            // if the lower bound is at s.begin() it means no person has completed watching his movie yet & thus this movie cannot be watched by anyone
            if(it != s.begin()){
                it--;
                // cout<<it->first<<" "<<it->second<<endl;
                s.erase(it);
                s.insert({endTime, i});
            }
            else { // this movie cannot be processed
                bad_movie_cnt++;
            }
        }
    }

    cout<<n - bad_movie_cnt<<endl;


    
    
}