// 1600 rated Graphs-topological sort
// handle corner cases

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


vector<char> adj[30];
vector<bool> vis;

int32_t main()
{
    initcode();
    int n; cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }      

    vector<int> indegree(26, 0);

    forn(i,n-1){
        string s1= v[i],s2=v[i+1];
        int k, len = min(s1.length(), s2.length());
        for(k=0;k<len; k++){
            if(s1[k]!= s2[k]) break;
        }

        // corner case: s1 is a subset of s2. Thats fine but the reverse is not valid
        if(k==len and s2.length() < s1.length()){
            cout<<"Impossible"<<endl;
            return 0;
        }

        // it implies s1 is a subset of s2-> valid
        if(k==len)continue;

        indegree[s2[k]-'a']++;
        adj[s1[k]-'a'].pb(s2[k]-'a');
    }


// topological sort
    queue<int> q;
    for(int i=0;i<26;i++){
        if(indegree[i]==0) {
            q.push(i);
         }
    }

    vector<int> res;

    while(!q.empty()){
        int f = q.front();
        res.pb(f);
        q.pop();
        for(int nb: adj[f]){
            indegree[nb]--;
            if(indegree[nb]==0) q.push(nb);
        }
    }


    if(res.size() != 26) cout<<"Impossible"<<endl;
    else{
        forn(i,res.size()) {
            char c = 'a'+res[i];
            cout<<c;

        }
        cout<<endl;
    }


    return 0;
}


