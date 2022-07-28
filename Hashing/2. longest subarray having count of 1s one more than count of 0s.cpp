// sum = 0 -> count of 1's  = count of 0's
// But we want count of 1's = count of 0's + 1
// 0 1 2 3 4 5 6 7 8
// | | | | | | | | | 
// <------>  <--->
//  x[0,4]   1[5,7]   // 0 to 4 sum is x and 0 to 7 sum is x+1 -> 5 to 7 is contributing 1
// <----------->
//    x+1[0,7]

// same logic is applied in finding largest subarray with 0 sum
//     0 1 2 3 4 5 6 7 8
//     | | | | | | | | | 
//     <-------> <--->      // 0 to 4 sum is x and 0 to 7 sum is x -> 5 to 7 is contributing 0
//        x        0
//     <------------->
//            x
int Solution::solve(vector<int> &A) {
    int len=0, s=0;
    map<int,int> mp;
    for(int i=0;i<A.size();i++){
        if (A[i]==1) s+=1;
        else s-=1;

        if (s==1){  // prefix sum corner case
            if(i+1 > len) len = i+1;
        }
        if (mp.find(s-1) != mp.end()){
            if(i-mp[s-1] > len){
                len = i-mp[s-1];
            }
        }
        if (mp.count(s) == 0) mp.insert({s,i});
    }

    return len;
}
