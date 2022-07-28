bool isValid(string s, vector<bool>& sieve){
    if(s.length()==4 and s[0]!='0'){
        int n=stoi(s);
        if(sieve[n]) return true;
    }
    return false;
}

int solve(int Num1,int Num2)
{   
    //code here
    // The classical Sieve of Eratosthenes algorithm takes O(N log (log N))
    vector<bool> sieve(10001, true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i*i<=10000;i++){
        if(sieve[i]){
            for(int j=i*i;j<=10000;j+=i){
                sieve[j]=false;
            }
        }
    }
    
    set<string> vis;
    
    string src=to_string(Num1);
    string dest = to_string(Num2);
    
    queue<string> q;
    q.push(src);
    vis.insert(src);
    
    int steps=0;
    
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            string f=q.front();
            q.pop();
            if(f.compare(dest)==0) return steps;
            for(int i=0;i<4;i++)
            {
                string t=f;
                for(char ch='0'; ch<='9'; ch++){
                    if(ch==t[i]) continue;
                    t[i]=ch;
                    if(!vis.count(t) and isValid(t,sieve)){
                        q.push(t);
                        vis.insert(t);
                    }
                }
            }
        }
        
        steps++;
    }
    
    
    return steps;
    
}