The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,

We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

Good questions to ask the interviewer :

What if n is greater than 10. How should multiple digit numbers be represented in string?
In this case, just concatenate the number to the answer.

 so if n = 11, k = 1, ans = "1234567891011"

Whats the maximum value of n and k?
In this case, k will be a positive integer thats less than INT_MAX.

n is reasonable enough to make sure the answer does not bloat up a lot.


// Below code is succesfully submiited on leetcode, refer tech dose video

string Solution::getPermutation(int n, int k) {
            vector<int> digit(n), fact(10, 0);
        for(int i=0;i<n;i++) digit[i] = i+1;
        
        fact[0] = fact[1] = 1;
        for(int i=2;i<10;i++){
            fact[i] = i*fact[i-1];
        }
        
        string res="";
        
        for(int i=n;i>=1;i--){
            int bi = ceil(k/(fact[i-1]*1.0)) - 1;
            res+=to_string(digit[bi]);
            digit.erase(digit.begin() + bi);
            k-=(fact[i-1]*bi);
        }
        
        return res;
}
