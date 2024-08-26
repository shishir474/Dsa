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
#define forn(i,n)       for(int i=0;i<n;++i)
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

int gcd(int a, int b)
{ // Time Complexity: O(Log min(a, b)) Auxiliary Space: O(Log (min(a,b))
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int32_t main()
{   
    /// logic: we try to converge all the elements to the min element. so first find the min element, then calculate the difference: arr[i] - mn for all i.
    // Now find the gcd of the all the differences. that is the max possible k value.
    // courner cases: While calculating gcd only consider non zero values.
    // If all values are zero ==> all elements are equal to min element aready, and in this case we can choose any max k value, so ans is -1
    // if only 1 non zero value is present then k is that non zero value. 
    // If we have >=2 non zero values, find the gcd of all of them. 
    // Now while finding gcd of an array, initialise gcd with gcd(arr[9],arr[1]), and then run loop from i=2 to n, and do GCD = gcd(GCD, arr[i]);
    // Ensure cases when arr size is 1 and 0.
    initcode();
    
    w(t){
        int n; cin>>n;
        int arr[n];
        forn(i,n) cin>>arr[i];
        int mn = *min_element(arr,arr+n);
        vector<int> temp;
        forn(i,n){
            if(arr[i]-mn > 0) temp.pb(arr[i]-mn); // push only non zero values, since we need to calculate gcd of all of them
        }
        if(temp.size()==0){
            cout<<"-1"<<endl; // all elements are same only so any arbitrarily large k can be taken
        }
        else if(temp.size()==1){
            cout<<temp[0]<<endl; // only 1 element is there that needs to be reduced, rest all are already equal to min element
        }
        else{
            int GCD=gcd(temp[0],temp[1]);
            fore(i,2,temp.size()-1){
                GCD = gcd(GCD,temp[i]);
            }
            cout<<GCD<<endl;
        }
        
    }
}