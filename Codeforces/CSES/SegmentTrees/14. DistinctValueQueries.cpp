/* Shishir Singh */
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
#define INF             1e18
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int modularBinaryExponentitation(int base, int exp) { return exp == 0 ? 1 : (modularBinaryExponentitation(base, exp / 2) * modularBinaryExponentitation(base, exp / 2) % mod * (exp % 2 ? base : 1)) % mod; }
int modinv(int b, int c){ return modularBinaryExponentitation(b, c-2);}
int log_a_with_base_b(int a, int b) { return log2(a) / log2(b); }
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void print_graph( vector<vector<int>> adj) { forn(i, adj.size()) { cout << i << ": "; forn(j, adj[i].size()) cout << adj[i][j] << " "; cout << endl; } }



int MAXN = 2e5+ 5;
int block_size;
struct Query{
    int l,r,idx;
};

struct cmp {
	bool operator()(const Query& a, const Query& b) {
             // a.l/block_size determines the block id where the left endpoint lies in
        if(a.l/block_size == b.l/block_size){       // so if both the interval's left end point lies in the same block, sort them by their right endpoint in increasing order
            return a.r < b.r;
        }
        return a.l/block_size < b.l/block_size;     // otherwise sort the queries on their block id's in increasing order 
	}
};

void printmap(map<int,int> &mp){
    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}


void coordinate_compression(vector<int>& arr){
    // create a copy of arr and remove all the duplicates
    vector<int> temp = arr;
    sort(all(temp));
    // remove all duplicates using unique() + erase()
    // unique returns an iterator pointing to the element following the last unique element 
    temp.erase(unique(all(temp)), temp.end());      // temp contains all unique values of arr
    unordered_map<int,int> compress_mp;     // map all unique values of arr to smaller index, starting from 0
    forn(i,temp.size()) compress_mp[temp[i]] = i;
    // replace the values in arr with its compressed form 
    forn(i,arr.size()) arr[i] = compress_mp[arr[i]];
}

signed main() {
    initcode();
    int n,q; cin>>n>>q;
    vector<int> arr(n);
    forn(i,n) cin>>arr[i];

    // maps each unique value in arr to a smaller index starting from 0
    // This modifies arr in place and replaces each value with its compressed form
    coordinate_compression(arr);

    block_size = sqrt(n);
    vector<Query> queries(q);
    forn(i,q){
        int l,r; cin>>l>>r;
        l--; r--;   // 0 - indexing
        queries[i] = {l,r,i};
    }
    
// we reorder the queries so that we can move the left and right pointers efficiently and minimise the cost of adding/removing elements 
    sort(all(queries), cmp());

    vector<int> ans(q);
    vector<int> freq(n,0);             //  Frequency array, since values are compressed to [0, n)
    // unordered_map<int,int> mp;      //   using freq[] instead of map

    int currL = 0, currR = -1;
    int cntDistinct = 0;

    auto add = [&](int idx){
        freq[arr[idx]]++;
        if(freq[arr[idx]] == 1) cntDistinct++;
    };

    auto remove = [&](int idx){
        freq[arr[idx]]--;
        if(freq[arr[idx]] == 0) cntDistinct--;
    };

    for(auto q: queries){
        int l=  q.l, r = q.r, index=  q.idx;
        
        while(currR < r){   // add all the elements from currR to r
            add(++currR);
            // currR++;
            // freq[arr[currR]]++;
            // if(freq[arr[currR]] == 1) cntDistinct++;
            // mp[arr[currR]]++;
            // if(mp[arr[currR]] == 1) cntDistinct++;
        }
        while(currL < l){   // remove all the elements from currL to l-1
            remove(currL++);
            // freq[arr[currL]]--;
            // if(freq[arr[currL]] == 0) cntDistinct--;
            // mp[arr[currL]]--;
            // if(mp[arr[currL]] == 0) cntDistinct--;
            // currL++;
        }   
        while(currL > l){   // add all the elements from currL - 1 to l
            add(--currL);
            // currL--;
            // freq[arr[currL]]++;
            // if(freq[arr[currL]] == 1) cntDistinct++;
            // mp[arr[currL]]++;
            // if(mp[arr[currL]] == 1) cntDistinct++;
        }
        while(currR > r){   // remove all the elements from currR to r+1
            // mp[arr[currR]]--;
            // if(mp[arr[currR]] == 0) cntDistinct--;
            remove(currR--);
            // freq[arr[currR]]--;
            // if(freq[arr[currR]] == 0) cntDistinct--;
            // currR--;
        }

        ans[index] = cntDistinct;
    }

    for(auto i: ans) cout<<i<<endl;
    cout<<endl;

    

    
    
    return 0;

}

// Mo’s Algorithm – Sorting Rationale

// Mo’s Algorithm is a sqrt-decomposition technique where we reorder queries to reduce the time complexity when answering range queries (e.g., [l, r]) on an array.

// 🧠 Notes
// 	•	You can further optimize performance by compressing values (coordinate compression) if values in the array are large.
// 	•	Mo’s algorithm is ideal when:
// 	•	You have offline queries (all queries are known beforehand).
// 	•	Each update/query change can be done in constant or small time.


// Why Coordinate Compression?

// When the array contains large numbers, using them as keys in a frequency map (like unordered_map<int,int>) can lead to:
// 	•	High memory usage.
// 	•	Slower lookups due to poor hash distribution.

// Instead, map each unique value to a smaller index starting from 0.

// Optimisations applied:
    // Used coordinate compression to map each unique value in arr to a smaller index, starting from 0. Since arr values could go upto a billion and we were using those as keys in our freq map, this would lead high memory consumption
        // array size <= 2e5+ 5 and arr value <= 1e9 . In the worse case we'll have 2e5+ 5 elements and since we have mapped each eleemnt to unique indexes, the max freq array size could be 2e5 + 5 
    // Started using freq[] instead of freq map. Not really clear about the reason behind this --> but this lead to acceptance of multiple test cases that were initially giving TLE 



// map vs unordered_map vs freq_array

// for unordered_map
//     Operation       Average case    Worst Case 
//     Insert             O(1)          O(N)
//     Find               O(1)          O(N)
//     Delete             O(1)          O(N)

// ⚠️ Why is Worst Case O(n)?

//     Because unordered_map uses hashing, and in rare cases:
//         •	All keys collide to the same bucket (due to bad hash function or malicious input).
//         •	The map ends up behaving like a linked list or a long chain.

//     However, in practice:
//         •	The average case is O(1) for all operations because of good hash functions and rehashing (automatic resizing of the internal bucket array).
//         •	Especially in competitive programming or Mo’s algorithm, worst-case rarely hits unless:
//         •	Hash collisions are forced.
//         •	Very large inputs with poor distribution.

// Insert / Find / Delete in unordered_map:
// 	•	✅ Average-case: O(1)
// 	•	⚠️ Worst-case: O(n), but rare in practice.


// map vs unordered_maps core difference
//     Feature                       map (std::map)                          unordered_map (std::unordered_map
//     Underlying DS                   Balanced BST (Red-Black Tree)           Hash Table
//     Time Complexity                 O(logn) for insert/find/delete          O(1) on average, O(n) worst-case
//     Ordered?                        Yes (sorted keys)                       No (random order)
//     Memory usage                    Lower                                   Higher due to hash table


// Why unordered_map is usually better for Mo’s Algorithm
//     1. Speed (O(1) vs O(log n))

//     In Mo’s Algorithm, we often call add() and remove() functions many times — especially when shifting the window.
//         •	Using map, each operation takes O(log n) time.
//         •	With unordered_map, it’s amortized O(1) — significantly faster when n is large or the number of queries is high.

//     2. We don’t need order

//     Mo’s Algorithm only cares about frequency counts — not the order of elements. So the ordering feature of map is wasted here.


// What does Amortized O(1) mean?
//     It means that on average, each operation takes constant time (O(1)), across a sequence of operations, even if some individual operations take longer.
//     Technical Example: 
//         vector::push_back()

//     	Most push_back() operations are O(1).
// 	•	But sometimes the vector has to resize (allocate new memory & copy everything).
// 	•	That resize takes O(n) time.
// 	•	However, resizing happens rarely (log(n) times for n inserts), so the average cost per push_back is O(1).

//         Hence:
//         👉 push_back() is amortized O(1).

//         🧠 In the context of unordered_map
// 	•	Most insert/find/erase operations are O(1).
// 	•	But if there’s rehashing (resize of internal hash table), that takes O(n).
// 	•	Since rehashing is rare, over many operations, the average time per operation stays constant.

//     So:
//     👉 unordered_map operations are amortized O(1).

//     ⸻

//     🔑 Key Takeaway

//         Amortized O(1) means you might pay a big cost once in a while, but on average per operation, it’s still constant time.



// ✅ Advantages of vector (freq array) over unordered_map
// Feature             vector<int> (freq array)                unordered_map<int, int>
// Access Time             O(1)                                    Amortized O(1), Worst-case O(n)
// Cache Friendliness      Excellent (contiguous)                  Poor (scattered in memory)

//     🤔 Why prefer a freq array over an unordered_map?

//     Once you’ve coordinate compressed your array, your values lie in a small range:
//     from 0 to n-1 (or distinct_values - 1).

//     ⚠️ When is unordered_map better?
//         If the values in your array:
//             •	Are very large (like up to 1e9)
//             •	Or not compressed to a tight range
//         Then using freq[value] would be memory inefficient or even crash.