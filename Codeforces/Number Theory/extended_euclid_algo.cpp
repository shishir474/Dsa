// ax + by = gcd(a,b)
// gcd(d,0) = d
// when b==0, ax + 0  = gcd(a,0) = a , x=1, y can be any integer, For simplicity taking y=0

// ax + by = gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// gcd(b,a%b) = bx1 + (a%b)y1
// a%b = a - (a/b)*b

// From above equations we get

// ax + by =  bx1 + (a%b)y1
// ax + by = bx1 + (a - (a/b)*b)y1
// ax + by = ay1 + b(x1-(a/b)*y1)

// x = y1 and y = x1 - (a/b)*y1

#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define endl            "\n"
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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
void SieveOfEratosthenes(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2;i*i<=n;i++){
        if (sieve[i]){
             // Update all multiples of i greater than or equal to its square which are multiple of i. Nos less than  p^2 are already been marked.
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }
}
int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool compare(pair<int,int>& p1, pair<int,int>& p2){
    if (p1.first == p2.first)
    return p1.second < p2.second;
    return p1.first < p2.first;
}
bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]){
            return false;
        }
    }
    
    return true;
}
void printGraph(vector<vector<int> >& adj, int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        int size = adj[i].size();
        for(int j=0;j<size;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){// bit is set
        return false;
    }else{
        return true;
    }
}

vector<int> adj[3000];
vector<bool> vis(2600, false);

// cycle detection
bool dfs(int sv, int par){
    vis[sv]=true;
    for(int nb: adj[sv]){
        if(!vis[nb]){
            if(dfs(nb,sv)) return true;
        }
        else if(vis[nb]==true and nb!=par) return true;
    }

    return false;
}

// ax + by = gcd(a,b)
// gcd(d,0) = d
// when b==0, ax + 0  = gcd(a,0) = a , x=1

// To find solution for ax+by=n
// Solution exists only if gcd(a,b) divides n
// ax1 + by1 = gcd(a,b) where x1 = x/n and y1 = y/n
// Solve this using standard extended_euclid algo to get x1 and y1
// x=  x1*(n/g)
// y = y1*(n/g)
// ax + by = gcd(a,b)*k
// a(x-b/g) + b(y+a/g) = gcd(a,b)*k = n

// Xall = (x - z*b/g)
// Yall = (y + z*a/g) 
// where z is an integer


struct triplet{
    int x,y,gcd;
};

triplet extended_euclid(int a, int b){ // gives sol. for ax+by=gcd(a,b)
    // cout<<a<<" "<<b<<endl;
    if(b==0){
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y=0;
        return ans;
    }

    triplet smallans = extended_euclid(b, a%b);
    triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (smallans.y*(a/b));
    return ans;
}
int32_t main()
{
    initcode();
    int n,a,b; cin>>n>>a>>b;

    if(n%gcd(a,b) != 0){
        cout<<"NO"<<endl;
    }
    else{
        triplet ans = extended_euclid(a,b); // gives solution for eqn: ax+by=gcd(,b)
        // cout<<"ans"<<endl;
        // cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;

// calculating solution for ax+by=k*gcd(a,b)=n
        int g = ans.gcd;
        int x = ans.x*(n/g);
        int y = ans.y*(n/g);
        
        // cout<<x<<" "<<y<<" "<<g<<endl;

        for(int k=-300;k<=300;k++){
            int newx = x - ((k*b)/g);
            int newy = y + ((k*a)/g);
            cout<<newx<<" "<<newy<<endl;
        }
    }

    
    return 0;
}



