Given arrival and departure times of all trains that reach a railway station, 
find the minimum number of platforms required for the railway station so that no train waits.
     We are given two arrays which represent arrival and departure times of trains that stop.

 Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.


// for string s=ADADAD..., platform required is 1
// s=ADAAADDDAADD, platform required is 3
// NOte string s is constructed after sorting time values combinedly for arrival and departure __TIME__

    int countConsecutiveAs(string s){
        int open=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if (s[i]=='A') open++;
            else open--;
            if(open > ans) ans = open;
        }
        
        return ans;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
        if(n==0) return 0;
        vector<pair<int,char> > v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i], 'A'});
            v.push_back({dep[i], 'D'});
        }
        sort(v.begin(),v.end());
        string s="";
        for(int i=0;i<v.size();i++){
            s.push_back(v[i].second);
        }
        return countConsecutiveAs(s);
    }

    TC: O(nlogn), sc:O(n);