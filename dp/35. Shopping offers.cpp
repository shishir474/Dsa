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

