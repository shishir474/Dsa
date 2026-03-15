638. Shopping Offers
In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.
You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.
Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.

 

Example 1:

Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
Example 2:

Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
Output: 11
Explanation: The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
 

Constraints:

n == price.length
n == needs.length
1 <= n <= 6
0 <= price[i] <= 10
0 <= needs[i] <= 10
1 <= special.length <= 100
special[i].length == n + 1
0 <= special[i][j] <= 50


// Intuition: -- knapsack pattern
I need to decide whether I need to consider ith offer or not. If I dont consider, then I simply move to next offer with needs unchanged. But if I consider that offer( it will be only considered if special[i][j] <= needs[j], because needs cant be negative)
add the offer cost and move to the next offer with the updated needs array. Another possible option is to purchase directly without any offers, which is simply the sum of needs[i]*price[i] for all i.
Base case:
if all the needs have been fulfilled --> return 0
else if we have exhausted all the offers, then we simply return the cost of buying all the items directly without any offers

We can memoise this (i,needs[]) i.e given the needs[] and i represents the #of offers remaining so far, what is the minimum cost to buy all the items.


class Solution {
public:
    // int t[102];
    
    void updateNeeds(vector<int>& needs, int i, vector<vector<int>>& special){
         for(int j=0;j<special[i].size()-1;j++){
            needs[j]-=special[i][j];
        }
    }
    
    void BacktrackNeeds(vector<int>& needs, int i, vector<vector<int>>& special){
        for(int j=0;j<special[i].size()-1;j++){
            needs[j]+=special[i][j];
        }
    }
    
    bool isValidOffer(int i, vector<vector<int>>& special,vector<int>& needs){
        for(int j=0;j<special[i].size()-1;j++){
            if(special[i][j] > needs[j]) return false;
        }
        return true;
    }
    
    bool noNeeds(vector<int>& needs){
        for(int i=0;i<needs.size();i++){
           if(needs[i] != 0) return false;
        }
        return true;
    }
    
    int directPurchase(vector<int>& price, vector<int>& needs){
        int ans=0;
        for(int i=0;i<needs.size();i++){
            ans+=needs[i]*price[i];
        }
        return ans;
    }

    
    // changing pareameter to i hai but dp lgayi hai needs pai, Hum needs ke basis pe computation krr rahe hai. Current needs ke lie kya cost hai voh store krre ahi
    int solve(int i, vector<vector<int>>& special, vector<int>& price, vector<int>& needs, map<vector<int>,int>& t){
        int n=special.size(),m=special[0].size();
        if(noNeeds(needs)) return 0;
        else if(i>=n){
            return directPurchase(price,needs);
        }
        else if(t.count(needs)) return t[needs];
        
    
        
        int ans=directPurchase(price,needs);
        
        
        if(isValidOffer(i,special,needs)){
            int m1 = solve(i+1,special,price,needs,t);
            updateNeeds(needs,i,special);
            int m2 = special[i][m-1] + solve(i,special,price,needs,t);
            BacktrackNeeds(needs,i,special);
            return t[needs] = min({ans,m1,m2});
        }
        else{
            return t[needs] =  min(ans, solve(i+1,special,price,needs,t));
        }
        
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //memset(t,-1,sizeof(t));
        // vector<int> t(102,-1);
        map<vector<int>,int> t;
        return solve(0,special,price,needs,t);
    }
};




// Last code written -- passes 64/65 test cases. The only problem here is I'm getting MLE for memoising (i,needs[]) in mp as opposed to memoising only needs in the above solution
Doubt: Why only memoising needs[] works here?

// You only need to memoize on needs[] (not (i, needs[])) because the order in which you consider special offers does not matter—you can use any offer any number of times, in any order.

// Why does memoizing only needs[] work?
// The state of the problem is fully determined by the current needs[] (how many of each item you still need to buy).
// For any given needs[], the minimum cost to satisfy those needs is always the same, regardless of which offer index i you are currently considering.
// Offers can be used any number of times and in any order, so the recursion will always explore all possible ways to use offers for a given needs[].
// If you memoize (i, needs[]), you are distinguishing between states that are actually equivalent (since the set of offers is always available for the current needs, regardless of the order).

// Why does memoizing (i, needs[]) cause MLE?
// The number of possible (i, needs[]) pairs is much larger than just the number of possible needs[] states.
// For each possible needs[], you could have up to special.size() different i values, leading to a huge number of memoization entries and thus Memory Limit Exceeded (MLE).

// Analogy
// Think of it like the Unbounded Knapsack problem:
// The state is defined by the current "capacity" (here, needs[]), not by which item you are currently considering.
// You can always try all items (offers) at each step.

// Summary
// Memoizing only needs[] is correct and optimal because the order of offers does not affect the result.
// Memoizing (i, needs[]) is unnecessary and leads to excessive memory usage.

class Solution {
public:
    bool noNeeds(vector<int>& needs){
        for(int i=0;i<needs.size();i++){
           if(needs[i] != 0) return false;
        }
        return true;
    }

    int directPurchase(vector<int>& price, vector<int>& needs){
        int ans=0;
        for(int i=0;i<needs.size();i++){
            ans+=needs[i]*price[i];
        }
        return ans;
    }

    bool isValidOffer(int i, vector<vector<int>>& special,vector<int>& needs){
        for(int j=0;j<special[i].size()-1;j++){
            if(special[i][j] > needs[j]) return false;
        }
        return true;
    }

    void updateNeeds(vector<int>& needs, int i, vector<vector<int>>& special){
         for(int j=0;j<special[i].size()-1;j++){
            needs[j]-=special[i][j];
        }
    }
    
    void backtrackNeeds(vector<int>& needs, int i, vector<vector<int>>& special){
        for(int j=0;j<special[i].size()-1;j++){
            needs[j]+=special[i][j];
        }
    }

    map<pair<int,vector<int>>, int> mp;

    // ith offer --> return the min cost required to satisfy the needs, given the choice you have i offers
    int solve(int i, vector<vector<int>>& special, vector<int>& price, vector<int>& needs){
        if(noNeeds(needs)) return 0;
        else if(i >= special.size()) { // all offers exhausted, directly purchase all the remaining needed items
            return directPurchase(price, needs);
        }
        // memoisation check -- check if (i,needs) pair already exists in mp -> return ans if it does
        if(mp.count({i,needs})) mp[{i,needs}];

        // if I dont consider ith offer     -- simply move to next offer(needs remains unchanged)
        int op1 = solve(i+1, special, price, needs);
        // 2nd option is I directly purchase all the remaining needed items
        int op2 = directPurchase(price, needs);  
        int ans = min(op1, op2);      
        // 3rd option: I choose to consider ith offer - but only in case if it's a valid one
        // ith offer will be considered valid only iff - all the items that we're getting as part of this offer <= our needs -- stated in the problem statement (last line)
        // and you could use an offer multiple times
        if(isValidOffer(i, special, needs)){
            updateNeeds(needs, i, special);             // you could use the same offer multiple times
            int op3 = special[i][special[i].size()-1] + solve(i, special, price, needs);
            ans = min(ans, op3);
            backtrackNeeds(needs, i, special);
        }

        return mp[{i,needs}] = ans;

    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // can memoise this solution for (i,needs) where i represents the starting index of reminaing offers and needs represents the current needs
        mp.clear();     // mp[pair(i,needs)] -> int. - reset the map
        return solve(0,special,price,needs);
    }
};


