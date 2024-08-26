//KEY IDEA: FastestFinger wins for $$$n=1$$$ , $$$n=2^x$$$ where ($$$x>1$$$) and $$$n= 2 \cdot p$$$ where $$$p$$$ is a prime $$$\ge 3$$$ else Ashishgup wins.



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
 
int calculate(int n, int k){
    if(n<=0) return 0;
    return ceil((n*1.0)/(k+1));
}

int32_t main()
{
    initcode();
    w(t){
        int n; cin>>n;
        if(n%2 == 1){
            if(n==1){
                cout<<"FastestFinger"<<endl;
            }
            else{
                cout<<"Ashishgup"<<endl;       
            }

            continue;
        } 

        // n even


// n is power of 2
        if((n&(n-1)) == 0){
            if(n==2){
                cout<<"Ashishgup"<<endl;            
            }
            else{
                cout<<"FastestFinger"<<endl;   
            }
        }
        else{
            int ans=0;
            for(int k=2;k<=sqrt(n);k++){
                if(n%k == 0){
                    int firstFactor = k, secondFactor = n/k;
                    if(k%2 and (n/k)!=2){
                        ans = 1; break;
                    }
                    else if(secondFactor%2 and (n/secondFactor)!=2){
                        ans= 1; break;
                    }
                }
            }

            if(ans){
                cout<<"Ashishgup"<<endl;            
            }
            else{
                cout<<"FastestFinger"<<endl;
            }
        }


    }


    return 0;
}



// TC: O(sqrt(n))
// sc: O(1)







// SOLUTION 2 USING DP -> gives runtime error, n can go upto 1e9 hence cannot use dp. NEED to solve it in O(1) space

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
 
int calculate(int n, int k){
    if(n<=0) return 0;
    return ceil((n*1.0)/(k+1));
}

int32_t main()
{
    initcode();
    w(t){
        int n; cin>>n;
        int dp[n+1];
        dp[1] = 0;
        for(int i=2;i<=n;i++){
            if(i%2==1){ // i odd case 
                dp[i] = 1; // implies ashish wins
            }
            else{  // i even case
                dp[i] = -1; // initialised with 0
                
                if(dp[i-1]==0) {dp[i]=1; continue;}

                for(int k=1;k<=sqrt(i);k++){
                    if(i%k == 0){
                        int firstFactor = k, secondFactor = i/k;
                        if(firstFactor%2==1 and dp[i/firstFactor]==0){
                            dp[i] = 1; break;
                        }
                        else if(secondFactor%2==1 and dp[i/secondFactor]==0){
                            dp[i]=1;  break;
                        }
                    }
                    
                }

                if(dp[i]==-1) dp[i]=0;

            }
        }

       
       
        if(dp[n]==1){
            cout<<"Ashishgup"<<endl;
        }
        else{
            cout<<"FastestFinger"<<endl;
        }

    }


    return 0;
}


// TC: O(N*sqrt(n))
// sc: O(n)