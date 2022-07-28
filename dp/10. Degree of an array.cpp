697. Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

solution:
1. find max freq 
2. The elements whose freq is equal to maxfreq-> if I choose that particualar subarray then its degree is equal to degree of nums, so determine the shortest subarray thats why stored first and last occurence of elements
So while traversing the map, if element freq is maxf then the array [i..j] could be possible ans (where i is the first and j is the last occurence of that element)


 
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        map<int,pair<int,int> > occurence; // nums[i]-> first and last occurence in array
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])==0) occurence[nums[i]].first = i; // first time
            occurence[nums[i]].second = i; // last time
            mp[nums[i]]++;
        }
        
        int mxf=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            mxf = max(mxf, it->second);
        }
        
        int ans=INT_MAX;
        for(auto it=mp.begin();it!=mp.end();it++){
            if (it->second==mxf){
                ans = min(ans, occurence[it->first].second-occurence[it->first].first+1);
            }
        }
        
        return ans;
        
    }