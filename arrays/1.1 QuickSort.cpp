#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define INF 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define fore(i, l, r) for (int i = l; i <= r; ++i)
#define all(v) v.begin(), v.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void initcode() {
    FIO;
}

// Comparator for the priority queue to prioritize cells with smaller distance
// struct cmp {
//     bool operator()(const cell &c1, const cell &c2) {
//         return c1.distance > c2.distance;
//     }
// };


vector<int> arr;

int partition(int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++){
        if(arr[j] < pivot){
            i++; swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int l, int r){
    if(l >= r) return;          // base case : empty or single element -- already sorted
    int pi = partition(l,r);
    quickSort(l,pi-1);
    quickSort(pi+1,r);
}
signed main() {
    initcode();
    int n; cin>>n;
    arr.resize(n);
    forn(i,n){
        cin>>arr[i];
    }

    quickSort(0,n-1);
    for(auto i: arr) cout<<i<<" ";
    
    
    return 0;
}

// avg case tc; O(nlogn)
// worse case tc: O(n^2) when the array is already sorted , parition() will take O(n) time during each call and the size of the input array will just reduce by 1 in the next recusion call leading to n^2 solution

// recursive stack space O(n) in the worst case.
// We are sorting the array in place.