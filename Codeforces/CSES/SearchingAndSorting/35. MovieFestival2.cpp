#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// and set.order_by_key(k) -> returns the index of the key k
// ordered set data structure => adds indexing functionality to sets

#define int             long long int
#define ff              first
#define ss              second
#define pb              push_back
// #define mp              make_pair
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
void initcode() {
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
int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}
int log_a_with_base_b(int a, int b){
        return log2(a) / log2(b);
}
void print_graph(vector<vector<int>> adj){
	forn(i,adj.size()){
		cout<<i<<": ";
		forn(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
int modularBinaryExponentitation(int base, int exponent) { // compute (a^b)%mod efficiently using binary exponentiation
	if(exponent==0) return 1;
	int val = modularBinaryExponentitation(base, exponent/2);
	if(exponent%2)
		return ((val*val)%mod*base)%mod;
	else
		return (val*val)%mod;
}

struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second < p2.second;
	}
};


signed main() {
    initcode();
    int n,k; cin>>n>>k;
    vector<pii> movies;
    forn(i,n){
        int start, end; cin>>start>>end;
        movies.push_back({start,end});
    }
    sort(all(movies),cmp()); // sort on end times 
    set<pii> s; // {endTime, index}
                // set will track the end times and since end times may not be unique, hennce using pii 
                
    int badcount = 0;

    // correct method Greedy approach:
        // Check if any existing individual can watch this movie and it is only possible if there exists an endtime <= start time of the current movie 
        //     Replace the older endtime with the current movie's end time 
        // If there does not exist any end time <= start time of the current movie, then no exinsting person can watch this movie. 
        //     Then we need to check if we have any free individuals. If yes -> that person can watch this movie 
        // If both of the above cases does not satisfy -> then we wont be able to watch this movie 
    for(int i=0;i<n;i++){
        int start = movies[i].first;
        int end = movies[i].second;
        auto it = s.upper_bound({start,i});
        if(it != s.begin()){    // if an existing person can watch a movie, only possible if there exists an end time <= current movie's start time
            it--;
            s.erase(it);
            s.insert({end,i});
        }
        else{   // at max set size will be k representing the end times of movies of k people 
            if(s.size() < k){   // if we have a person, who isn't occupied, 
                s.insert({end,i});
            }
            else{   // nobody can watch this movie 
                badcount++;
            }
        }
    }

    // These method is wrong:
        // Here we directly assinging movies to new individuals until all the k persons have been occupied and then later checking if any person is free to watch this movie 

    // for(int i=0;i<n;i++){
    //     int start = movies[i].first;
    //     int end = movies[i].second;
    //     if(s.size() < k){ // if a new person is remaining --> they can watch this movie
    //         s.insert({end,i});
    //     }
    //     else{// if any existing person can watch - only possible if there exists an end time < current movie's start time
    //         auto it = s.upper_bound({start,i});
    //         if(it != s.begin()){
    //             it--;
    //             s.erase(it);
    //             s.insert({end,i});
    //         }
    //         else{
    //             badcount++;
    //         }

    //     }
        
    // }

// max no of watched movies 
    cout<<n-badcount<<endl;

    
    return 0;
}
// Below solution will ensure the most optimal ans:
// can an existing person watch a movie -> for this check set. Check if there exists any person whose movie's end time < movie[i].start, then he can watch that movie (so remove the exising pair, and insert the new end time, idx pair)
// do we have any new persons remaining -> if yes, then he can watch this movie (if the set.size() < k) which means there are some persons remaining and one of them could surely watch this movie 
// movie cannot be watched -> There are no persons remaining and all of their movies have end_time >= movies[i].start

