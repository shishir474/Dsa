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

// Structure to represent a cell in the priority queue
struct cell {
    int distance, node;
    cell(int d, int sv) {
        distance = d;
        node = sv;
    }
};

// Comparator for the priority queue to prioritize cells with smaller distance
struct cmp {
    bool operator()(const cell &c1, const cell &c2) {
        return c1.distance > c2.distance;
    }
};

vector<vector<pii>> adj; // Adjacency list to store the graph
int N, total_dist, total_paths, minLen = INF, maxLen = 0;

void djkstra() {
    // Arrays to store:
    // dist[v]: Shortest distance from node 1 to node v
    // count[v]: Number of shortest paths from node 1 to node v
    // minLenArr[v]: Minimum length of the shortest path from node 1 to node v
    // maxLenArr[v]: Maximum length of the shortest path from node 1 to node v
    vector<int> dist(N + 1, INF), count(N + 1, 0), minLenArr(N + 1, INF), maxLenArr(N + 1, 0);
    
    // Initialize distance, count, minLenArr, and maxLenArr for the starting node (node 1)
    dist[1] = 0;
    count[1] = 1; // There is exactly one way to be at the starting node
    minLenArr[1] = 0; // Length of the path to the starting node is 0
    maxLenArr[1] = 0; // Length of the path to the starting node is 0

    // Priority queue to process nodes in order of increasing distance
    priority_queue<cell, vector<cell>, cmp> pq;
    pq.push(cell(0, 1)); // Push the starting node with distance 0 and length 0

    while (!pq.empty()) {
        // Extract the node with the smallest distance
        cell c = pq.top();
        int d = c.distance;
        int u = c.node;
        pq.pop();

        // If the extracted distance is greater than the current known distance, skip
        if (d > dist[u]) continue;

        // Explore all neighbors of the current node
        for (auto it : adj[u]) {
            int v = it.first, wt = it.second;

            // If a shorter path to v is found
            if (d + wt < dist[v]) {
                dist[v] = d + wt; // Update the shortest distance
                count[v] = count[u]; // Reset the count of shortest paths
                minLenArr[v] = minLenArr[u] + 1; // Update the minimum length
                maxLenArr[v] = maxLenArr[u] + 1; // Update the maximum length
                pq.push(cell(dist[v], v)); // Push the updated node into the queue
            }
            // If another path with the same distance is found
            else if (d + wt == dist[v]) {
                count[v] = (count[v] + count[u])%mod; // Increment the count of shortest paths
                minLenArr[v] = min(minLenArr[v], minLenArr[u] + 1); // Update the minimum length
                maxLenArr[v] = max(maxLenArr[v], maxLenArr[u] + 1); // Update the maximum length
            }
        }
    }

    // Store the results for the destination node (node N)
    total_dist = dist[N];
    total_paths = count[N];
    minLen = minLenArr[N];
    maxLen = maxLenArr[N];

    // Output the results
    cout << total_dist << " " << total_paths << " " << minLen << " " << maxLen << endl;
}

signed main() {
    initcode();
    int n, m;
    cin >> n >> m;
    N = n;
    adj.resize(n + 1);

    // Read the graph edges
    forn(i, m) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt}); // Add a unidirectional edge from u to v with weight wt
    }

    // Run Dijkstra's algorithm to compute the required values
    djkstra();
    return 0;
}