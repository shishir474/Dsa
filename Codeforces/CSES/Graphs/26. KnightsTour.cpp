#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)

vector<vector<int>> board(8, vector<int>(8, -1)); // Initialize board with -1 (unvisited)

// Possible moves for the knight
int X[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

void printboard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << setw(2) << board[i][j] << " "; // Formatting for better visualization
        }
        cout << endl;
    }
}

// Function to count possible next moves from (x, y)
int countMoves(int x, int y) {
    int count = 0;
    for (int k = 0; k < 8; k++) {
        int newx = x + X[k], newy = y + Y[k];
        if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8 && board[newx][newy] == -1) {
            count++;
        }
    }
    return count;
}

// Comparison function for sorting moves based on Warnsdorff’s heuristic
bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    return countMoves(p1.first, p1.second) < countMoves(p2.first, p2.second);
}

// Instead of checking all the valid positions which is inefficient and eventually causes stack overflow bcoz of huge no of possibilities
// we use Warnsdorff’s heurestics that gives us the moves in the order that has a highest probability of leading to a solution
// Warnsdorff’s heuristic counts the no of possible moves for each position
// we sort the vector nextMoves in ascending order based on Warnsdorff’s heurestics 
// This sorting ensures that positions with fewer onward moves come first in nextMoves.


// DFS function for Knight’s Tour with Warnsdorff’s heuristic
bool dfs(int x, int y, int moves) {
    board[x][y] = moves; // Assign move number
    if (moves == 64) return true; // Solution found

    vector<pair<int, int>> nextMoves;
    for (int k = 0; k < 8; k++) {
        int newx = x + X[k], newy = y + Y[k];
        if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8 && board[newx][newy] == -1) {
            nextMoves.push_back({newx, newy});
        }
    }

    // Sort next moves based on the number of onward moves (Warnsdorff’s heuristic)
    sort(nextMoves.begin(), nextMoves.end(), cmp);

    // Try all possible moves
    for (auto &[nx, ny] : nextMoves) {
        if (dfs(nx, ny, moves + 1)) return true;
    }

    // Backtrack if no solution found
    board[x][y] = -1;
    return false;
}

// definitely you can move in the random order and check if we can assign all 64 moves. 
// But sorting the valid positions(based on x axis) ensures that we approach those cells first which has fewer onward moves 

signed main() {
    int x, y;
    cin >> x >> y; // Read starting position (1-based index),  x is col and y is row
    swap(x,y); //  swapping coz of the way input is provided in the problem statement
    // the only thing which varies across all the test cases is my starting position
    // I will start 

    if (dfs(x - 1, y - 1, 1)) {
        printboard();
    } else {
        cout << "-1" << endl; // No solution found
    }
}




// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,  tree_order_statistics_node_update>;  // policy based data structure
// // ordered_set is a pbds which is similar to set and has 2 extra functionalities set.find_by_order(idx) -> returns the element at this index
// // and set.order_by_key(k) -> returns the index of the key k
// // ordered set data structure => adds indexing functionality to sets

// #define int             long long int
// #define ff              first
// #define ss              second
// #define pb              push_back
// // #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define forn(i,n)      for(int i=0;i<n;++i)
// #define fore(i, l, r)   for(int i = l; i <= r; ++i)
// #define all(v)          v.begin(), v.end()

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// void initcode() {
// 	FIO;
// 	// #ifndef ONLINE_JUDGE
// 	// freopen("cpp/input.txt", "r", stdin);
// 	// freopen("cpp/output.txt", "w", stdout);
// 	// #endif // ONLINE_JUDGE
// }
// int gcd(int a, int b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }
// int lcm(int a, int b) {
// 	return (a / gcd(a, b) * b);
// }
// int log_a_with_base_b(int a, int b){
//         return log2(a) / log2(b);
// }
// void print_graph(vector<vector<int>> adj){
// 	forn(i,adj.size()){
// 		cout<<i<<": ";
// 		forn(j,adj[i].size()){
// 			cout<<adj[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }
// int modularBinaryExponentitation(int base, int exponent) {
// 	if(exponent==0) return 1;
// 	int val = modularBinaryExponentitation(base, exponent/2);
// 	if(exponent%2)
// 		return ((val*val)%mod*base)%mod;
// 	else
// 		return (val*val)%mod;
// }

// struct cmp {
// 	bool operator()(const pii& p1, const pii& p2) {
// 		return p1.second < p2.second;
// 	}
// };

// vector<vector<int>> board(8, vector<int>(8,-1));

// void printboard(){
//     for(int i=0;i<8;i++){
//         for(int j=0;j<8;j++){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// void dfs(int x,int y, int moves){
//     board[x][y] = moves
//     if(moves == 64){
//         printboard();
//         return;
//     }
//     for(int k=0;k<8;k++){
//         int newx = x+X[k], newy = y+Y[k];
//         if(newx>=0 and newx<8 and newy>=0 and newy<8 and board[newx][newy]==-1){  //board[newx][newy]==-1 signifies newx,newy is not visited
//             dfs(newx,newy,moves+1)
//         }
//     }
//     board[x][y]=-1;
// }
// signed main() {
//     initcode();
//     int x,y; cin>>x>>y;
//     dfs(x,y,1);
    
// }






