// https://www.youtube.com/watch?v=s8e3Gy7H9iw&t=144s&ab_channel=NeatlyStructured

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
        return p1.first > p2.first;  // Compare by first element
    }
};


signed main(){
    /// sort the customers on the arrival time
    // store the original index bcoz we have to report ans in that order only - after sorting the order will change
    // we have to track the min exit time of all the rooms occupied - can use multiset or pq
    // TC: O(nlogn) push & pop is O(logn) in pq and pq.top() is O(1)
    initcode();
    int n; cin>>n;
    vector<pair<pii,int>> v;
    forn(i,n){
        int start, end; cin>>start>>end; 
        v.pb({{start,end},i}); // storing the start, end & index of the customers, bcoz after sorting their positions will change. We need to retain their positions
    }
    // sort on basis of start time
    sort(all(v)); 
    // min pq (end_time, room_id)
    priority_queue<pii, vector<pii>, cmp> pq; // pii -> {end_time, room_id}
    vector<int> rooms_assigned(n);
    int next_avail_room = 1;
    forn(i,v.size()){ // sorted vector
        if(pq.size()==0){// 1st customer: have to assign a new room
            rooms_assigned[v[i].second] = next_avail_room; // assign the room
            pq.push({v[i].first.second, next_avail_room}); // block the room by pushing the (end_time,room_id)
            next_avail_room++;
        }
        else{ // if pq.top() end time < arrival time: can use existing room at the pq.top()
        // pq tracks the min exit time of all the rooms occupied - so that this room can be assigned to the new customer
            if(pq.top().first < v[i].first.first){ 
                rooms_assigned[v[i].second] = pq.top().second;
                pq.pop(); // update the end time for the room so remove and insert new pair with latest end time
                pq.push({v[i].first.second, rooms_assigned[v[i].second]});
            }
            else{ // allot new room
                rooms_assigned[v[i].second] = next_avail_room;
                pq.push({v[i].first.second, next_avail_room});
                next_avail_room++;
            }
        }
        
    }

    cout<<next_avail_room-1<<endl;
    forn(i,n) cout<<rooms_assigned[i]<<" ";
    cout<<endl;
    
    return 0;
    
    
}

