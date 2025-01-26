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
        return p1.first < p2.first;  // Compare by first element
    }
};


signed main(){
    initcode();
    int n,k; cin>>n>>k;
    ordered_set<int> o_set;
    fore(i,1,n)
        o_set.insert(i);
    int start = 0;
    while(o_set.size() > 0){
        int pos = (start+k)%o_set.size();
        auto t = o_set.find_by_order(pos);
        cout<<*t<<" ";
        o_set.erase(t);
        start = pos;
    }

    return 0;
    
    
}




// ordered_set data structure, which is implemented in C++ using Policy-Based Data Structures available in the GNU C++ STL. It extends the capabilities of the standard set or multiset with additional features like indexing and order statistics.

// The ordered_set is typically implemented using the tree template from the ext/pb_ds (policy-based data structures) library.

// Features of ordered_set:
// 	1.	All standard set operations:
// 	•	Insert
// 	•	Erase
// 	•	Find
// 	•	Lower and Upper Bound
// 	2.	Order Statistics:
// 	•	find_by_order(k): Finds the k-th smallest element (0-based index).
// 	•	order_of_key(x): Finds the number of elements strictly less than x.

// Implementation:

// Here is an example of how to use an ordered_set:


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;

    // Insert elements
    os.insert(10);
    os.insert(20);
    os.insert(15);

    // Find k-th smallest element (0-based indexing)
    cout << *os.find_by_order(0) << endl; // Output: 10
    cout << *os.find_by_order(1) << endl; // Output: 15

    // Count of elements strictly less than x
    cout << os.order_of_key(15) << endl; // Output: 1
    cout << os.order_of_key(25) << endl; // Output: 3

    // Check if an element exists
    if (os.find(20) != os.end()) {
        cout << "20 exists in the set" << endl;
    }

    return 0;
}

// Explanation of Template Parameters:
// 	1.	Key Type (int): Type of the elements in the set.
// 	2.	Mapped Type (null_type): For sets, null_type is used because no associated values are stored. For maps, you can use an appropriate type.
// 	3.	Comparator (less<int>): Comparison function, e.g., less<int> for ascending order or greater<int> for descending order.
// 	4.	Tree Structure (rb_tree_tag): Red-Black tree is used as the underlying data structure.
// 	5.	Update Policy (tree_order_statistics_node_update): Policy that enables order statistics.



// Use Cases:
// 	1.	Finding the k-th smallest or largest element efficiently.
// 	2.	Maintaining a sorted structure while allowing index-based access.
// 	3.	Dynamic range queries and ranking operations.

// Time Complexity:
// 	•	Insertion, Deletion, find_by_order, and order_of_key: O(\log n).



// Does it store elements in a sorted fashion
// Yes, the ordered_set stores elements in a sorted order, just like the standard std::set or std::map. It is implemented using a red-black tree as the underlying data structure, which ensures that elements are always sorted according to the comparison function you specify (e.g., less<int> for ascending order or greater<int> for descending order).

// Key Points About Sorting in ordered_set:
// 	1.	Automatic Sorting: When you insert an element, it is placed in the correct position in the sorted sequence.
// 	2.	Custom Sorting Order: You can define your sorting order using a comparator:
// 	•	Default: less<int> (ascending order).
// 	•	Custom: greater<int> (descending order) or any custom comparator.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;

    // Insert elements
    os.insert(30);
    os.insert(10);
    os.insert(20);

    // Display elements in sorted order
    for (auto x : os) {
        cout << x << " "; // Output: 10 20 30
    }
    cout << endl;

    // Insert more elements
    os.insert(15);

    // Sorted elements after new insertion
    for (auto x : os) {
        cout << x << " "; // Output: 10 15 20 30
    }

    return 0;
}



typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_desc;

int main() {
    ordered_set_desc os;

    os.insert(30);
    os.insert(10);
    os.insert(20);

    for (auto x : os) {
        cout << x << " "; // Output: 30 20 10 (descending order)
    }
}

// In this case, the elements are stored in descending order because the comparator is greater<int>.

// So yes, ordered_set always keeps its elements sorted, and you can control the sorting order through the comparator.