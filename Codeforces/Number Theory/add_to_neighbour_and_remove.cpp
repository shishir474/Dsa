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

bool check(int i, int arr[], int n, int curr_sum, int no_of_parts, int ele, int desired_parts){
    // cout<<"i: "<<i<<" "<<"cs: "<<curr_sum<<"parts: "<<no_of_parts<<endl; 
    if(i==n){
        if(no_of_parts==desired_parts and curr_sum==0) return true;
        return false;
    }
    curr_sum+=arr[i];
    if(curr_sum > ele) return false;
    if(curr_sum == ele){
        no_of_parts++;
        curr_sum=0;
    }

    return check(i+1,arr,n,curr_sum,no_of_parts,ele,desired_parts);
}


// checks if k operations can be done on the array or not
bool solve(int k, int arr[], int n, int s){
    if(s%(n-k) != 0) return false;

    int ele = s/(n-k);
    // checks if the array can be broken down into n-k parts where each part is equivalen to ele
    int curr_sum=0;
    if(check(0,arr,n,curr_sum,0,ele,n-k)) return true;
    return false;
}
int32_t main()
{   
    initcode();

    w(t){
        int n; cin>>n;
        int arr[n];
        forn(i,n) cin>>arr[i];
        int sum=arr[0];
        bool all_equal=true;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[0]) {
                all_equal=false;
            }
            sum+=arr[i];
        }
        if(all_equal) { // if all elements equal no operations needed to be done
            cout<<"0"<<endl;
            continue;
        }

        int ans=n-1,k=n-2;
        while(k>0){
            if(solve(k,arr,n,sum)){
                ans=k;
            }
            k--;
        }

        cout<<ans<<endl;

    }
}