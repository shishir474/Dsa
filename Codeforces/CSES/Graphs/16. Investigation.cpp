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


// In this problem we have to find the below things
// 1 What is the minimum cost of from src to dest.
// 2. How many such minimum cost paths exists.
// 3. What is the shortest length of the min cost path.
// 4. What is the longest length of the min cost path.

// NOTE: Everything is related to min cost path. and since all the edge weights are +ve, djkstra is the clear choice for us
// Remeber edge weight either indicates distance from u to v or cost from u to v. Here we are calling it cost 

// For djkstra, we need
// 1. dist[] or cost[] which will track the minimum distance from src to ith vertex. This array will be initialsed with inf for all i's and dist[src] = 0 or cost[src] = 0 (basically distance of the src from itself is gonna be 0)
// 2. we need a min heap or a priority queue to store the vertices in the ascending order of their distances/costs from the src. We'll track (dist,node)

// Djkstra Logic:
// 1. Initialise the dist[] or cost[]
// 2. create a min heap and push the (0,src) into your heap
// 3. Process until pq is not exhausted. Benefit of using a pq is this will always give you min dist vertex(). So you'll be processing the vertices in increasing order of their distance or cost from the src 
// 4. each pq element will store 2 things dist/cost (d) & node. This d represents the distance with which we have reached the current node. This d <= distance[node] must hold true. If it doesnot, then it means we are reaching the current node with a distance which is > dist[node] and this will obviusly increase the cost of reaching node(so no need for processing this path) 
// 5. At the end of this loop, you'll have your distance array[] populated

// Here in addition to finding the min cost we also need to find a bunch of different things like count of paths, min length of the path, max length of the path
// We can maintain a separate [] for tracking each of this.
// For instance, when I'm at a certain node I've 2 things(node and distance(d) with which we reached that node).
// Now while processing the neigbhours of this node, we check if d + edgeWeight <= dist[nb]. If this holds, we found a better path of reaching nb and thus we update dist[nb]
// This condition can be broken down into 2 subconditions:
// 1. if d + edgeWeight < dist[nb] (strictly less -- meaning we found a better path)
// 2. If d + edgeWeight == dist[nb] (found one new path with the same distance, so count will be udpated )

// In case 1:                   -- here we reset the values with the newer ones 
    //  dist[v] = dist[u] + edgeWeight      -- update the dist[v] with better distance
    //  countPaths[v] = countPaths[u]       -- reset the count of paths. no of ways of reaching v will be equal to no of ways of reaching u
    //  minLen[v] = minLen[u] + 1           -- reset the length. minLen[u] stores min length of reaching u, v is at a distance of 1 from u
    //  maxLen[v] = maxLen[u] + 1           -- reset the length. maxLen[u] stores max length of reaching u, v is at a distance of 1 from u
// case 2:                      -- here we compare & update the values 
    // distance remains the same        
    // countPaths[v] += countPaths[u]       -- I'm reaching at the same cost, but my countPaths will increase
    // minLen[v] = min(minLen[v],  minLen[u] + 1)                      -- compare with the existing value and update. 
    // maxLen[v] = max(maxLen[v],  maxLen[u] + 1)                      -- compare with the existing value and update. 


    // assuming I'm reaching u with 5 cost and their are 10 ways for acheiving this
    // 


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