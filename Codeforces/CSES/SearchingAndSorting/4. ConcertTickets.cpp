#include <bits/stdc++.h>
using namespace std;

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

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("cpp/input.txt", "r", stdin);
    freopen("cpp/output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
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

signed main(){
    int n,m; cin>>n>>m;
    int a[n], b[m];
    set<pair<int,int>> s;
    
    forn(i,n) {
        cin>>a[i];
        s.insert({a[i], i});
    }
    forn(i,m) cin>>b[i];
    
    
    
    forn(i,m){
        // cout<<"b[i] "<<b[i]<<endl;
        // for(auto it: s){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<endl;
        
        auto it = s.upper_bound({b[i],INT_MAX});  // O(logn) How comparison works in case of pair of elements
        if(it==s.begin()){
            cout<<"-1"<<endl; continue;
        }
        it--;
        cout<<it->first<<endl;
        s.erase(it);      // O(logn)
    }
    
    
   
    
}


// What Happens with upper_bound({8, 0}):
// upper_bound({8, 0}) will return an iterator to the first pair strictly greater than {8, 0}.

// It compares {8, 0} with the elements:

// (5, 0) → Not greater.
// (5, 4) → Not greater.
// (7, 2) → Not greater.
// (8, 3) → This is greater than {8, 0} (since 3 > 0).
// Thus, upper_bound({8, 0}) will return an iterator pointing to (8, 3).

// Hence due to this reason we find upper_bound of ({b[i], INT_MAX}), instead of {b[i],0}




// set.upper_bound() is logn
// multiset.upper_bound() is logn -- Multiset is very similar to set, just that it also retains duplicates as well
// mp.upper_bound() is logn
// upper_bound(all(v), x) is logn 
// set.erase is logn()



// Erasing elements from the vector is O(n), hence used sets. In sets erase operation takes O(logn) time
// But sets only stores unique elements, so how will we retain elements that are duplicates. Hence used set of pair of integers pair<int,int> = {value, index}

// Could have also used multisets: 
    // multisets unlike sets allows duplicate elements to be inserted. Insertion/erase is log(n) like sets. Elements are stored in sorted order by default

// In sets all the elements are stored in sorted order, hence we could use upper/lower bound. Also erasing element is Log(n)



// In sets the elements are by default stored in sorted order. But we can change this default behaviour to store eleemnts in desc order as well

// set<int, greater<int>> s;

// // Insert elements
// s.insert(10);
// s.insert(5);
// s.insert(20);
// s.insert(15);

// for(auto i: s){
//     cout<<i<<" ";
// }

// // We can also use custom comparators

// struct cmp{
//     bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
//         if(p1.first == p2.first)
//             return p1.second > p2.second;
//         return p1.first > p2.first;
//     }
// };

// int main(){
//     set<int, cmp> s1; 
//     // Insert pairs
//     s.insert({5, 0});
//     s.insert({8, 3});
//     s.insert({7, 2});
//     s.insert({5, 4});
//     for(auto &p: s1){
//         cout<<p.first<<" "<<p.second<<endl;
//     }
// }
