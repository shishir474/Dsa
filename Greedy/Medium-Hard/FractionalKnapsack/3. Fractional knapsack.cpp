Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 


// Prioritise items that offers better value per unit weight.
// This works because we are allowed to take fractions of items. So we would want to maximise the value we get for each unit of weight we add to the knapsack.

// On the other hand, for 0/1 knapsack, this value per unit weight approach does not work because we are not allowed to take fractions of items (we either take the whole item or leave it).
// For each item, there are 2 choices, either we take it or we don't. Will be solved using recursion where we'll explore all possible combinations.

1st item : value = 60 , weight = 10
since weight <= cap, I can take this item. The other option is I choose to ignore it. 

                            0,0,50
                            / \
                      1,0,50    1,60,40
                     /  \
                2,0,50  2, 100,30
                / \     /     \
            3,0,0  3,120 3,100  3, 220


            f(idx, cap):
                if idx >= n:
                    return profit

                ans = f(idx + 1, cap) // not take
                
                if(weights[idx] <= cap)
                    ans = max(ans,
                            values[idx] + f(idx + 1, cap - weights[idx]) // take 
                        )
                
                return ans

            dp[n+1][cap+1]
                for i in range(n+1):
                    for j in range(cap+1):
                        if i == 0 or j == 0:
                            dp[i][j] = 0
                        else:
                            // ith item and j capacity
                            dp[i][j] = dp[i-1][j] // not take
                            
                            // I can only take it iff weight of ith item <= capacity
                            if weigth[i-1] <= j:
                                dp[i][j] = max(dp[i][j], values[i-1] + dp[i-1][j-weight[i-1]])


            return dp[n][cap]
                
----------------------------------------------------------------------------------------------------


struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item i1, Item i2){
        double a=i1.value/(i1.weight*1.0);
        double b=i2.value/(i2.weight*1.0);
        return a > b;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        double ans=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight <= W){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                ans+=(arr[i].value*W)/(arr[i].weight*1.0);
                break;
            }
        }
        
        return ans;
        
    }
        
};






Similar problem, same logic is used

In a stock market, there is a product with its infinite stocks. The stock prices are given for
N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the
maximum number of stocks a customer can buy. 


First Day: stock price : 10, and I can buy atmost 1 stock  # of stocks per unit price: 0.1
Second day: stock price: 7 and I can buy 2 stocks at max   # of stocks per unit price: 0.7
third day: stock price: 19 and I can buy 3 stocks at max   # # of stocks per unit price: 0.04

I need to find max no of stocks that I buy. 
for this I would want to utilise my capacity to the fullest which means for each rupee, what is the max no of stocks that I can buy 


(10,1), (7,2), (19,3)

sort on basis of # of stocks per unit price in decreasing order or I can say sort in increasing order to stock prices
(7,2), (10,1),(19,3)

capacity = 45 
idx:0 -- > I can buy atmost 2 stocks. Can I buy both 7*2 = 14 < 45. Yes I can. stocks_bought = 2, capacity = 31
idx: 1 --> I can buy atmost 1 stock. can I buy them all? 10*1 < 31. Yes. stocks_bought = 3, capacity = 21
idx: 2 --> I can buy atmost 3 stocks. Can I buy them all? 19*3 < 21. No I cannot buy all. I can only buy one. stocks_bought = 4, capacity = 2



Input:
price[] = { 10, 7, 19 }
k = 45
Output: 4
Explanation: A customer purchases 1 stock on day 1, 
2 stocks on day 2 and 1 stock on day 3 for 
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

sol.
we have to maximise the no of stocks, so bought the stock which is cheapest. If we can buy its entire quantity add that many stocks to ans and update k
keep on doing this until we cannot buy the whole the whole stack/k is reduced to 0

int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i+1});
        }
        sort(v.begin(),v.end());
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first*v[i].second <= k){
                c+=v[i].second;
                k-=(v[i].first*v[i].second);
            }
            else{
                c+=(k/v[i].first);
                break;
            }
        }
        
        return c;
    }