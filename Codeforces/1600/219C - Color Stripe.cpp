// 1600 Rated

#include<bits/stdc++.h>
using namespace std;

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
{
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
    return p1.second < p2.second;
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

bool checkUnsetBit(int n, int i){
    if ((n&(1<<i)) != 0){
        return false;
    }else{
        return true;
    }
}

int32_t main()
{   
    initcode();
    int n,k; cin>>n>>k;
    string s; cin>>s;

    // k==2 case handled seperately
    if(k==2){
        int op1= 0, op2=0;
        forn(i,n){
            if(i%2 == 0 and s[i]=='B') op1++;
            else if(i%2==1 and s[i]=='A') op1++;
        }
        forn(i,n){
            if(i%2 == 0 and s[i]=='A') op2++;
            else if(i%2==1 and s[i]=='B') op2++;
        }

        if(op1<op2){
            cout<<op1<<endl;
            forn(i,n){
                if(i%2 == 0) cout<<"A";
                else cout<<"B";
            }
            cout<<endl;
        }
        else{
            cout<<op2<<endl;
            forn(i,n){
                if(i%2 == 0) cout<<"B";
                else cout<<"A";
            }
            cout<<endl;
        }
    }
    // when k >= 3
    else{
        int res=0;

        int i,j;
        for(i=0;i<n; ){
            for(j=i+1;j<n and s[i]==s[j] ; j++){}
            
            string t = s.substr(i,j-i); // start from i and length is j-i
            
            res+=t.length()/2;
            
            if(t.length()%2 == 1){   // update 2,4 the pos wale characters
                char c;
                for(int p=0;p<k;p++){
                    if('A'+p != s[i]) { c='A'+p; break;}
                }
                for(int p=i+1;p<j-1; p+=2) s[p]=c;

            }
            else{  // update 2,4 6th pos wale characters

                char c;

                if(j==n){  // s[j] doesnt exist
                    for(int p=0;p<k;p++){
                        if('A'+p != s[i]) { c='A'+p; break;}
                    }
                }
                else{ // s[j] exists
                    for(int p=0;p<k;p++){
                      if('A'+p != s[i] and 'A'+p !=s[j]) { c='A'+p; break;}
                    }
                }
                
                for(int p=i+1;p<j; p+=2) s[p]=c;
            }

            i = j;
        }

        cout<<res<<endl;
        cout<<s<<endl;

    }


    return 0;
        
}


// Solution:
// C :: Color Stripe
// There are two cases to consider , when K=2 and when K>2. For K=2 there are only two possible solutions: the string "ABABAB..." and "BABABA..."

// For both strings, simply count the number of differences between it and the given string and print a string with fewer differences.

// For K>2 , decompose the string into contiguous single-colored sequences. Observe one such sequence. If it has an odd number of characters, say 2m+1, replace m characters with some other character in the following fashion:

// AAAAA

// becomes

// ABABA

// It can be observed that by changing less than m characters doesn't remove all pairs of adjacent identical characters. Similarly, for sequences of even length, say 2m characters, observe a character in the original string right after the last character of the observed sequence, and choose a character different from both. Example:

// AAAAAAB

// becomes

// ACACACB

// Again, it is sufficient and necessary to change m characters.