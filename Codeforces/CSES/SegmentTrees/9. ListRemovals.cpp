#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>; 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);  // Stores the list elements
    ordered_set<int> indices;    // Ordered set to track valid indices

    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        indices.insert(i);  // Store initial positions (0-based index)
    }

    // Process removal operations
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        auto it = indices.find_by_order(p);
        int pos = *it;
        indices.erase(it);
        cout<<arr[pos]<<" ";
    }

    cout << endl;
    return 0;
}