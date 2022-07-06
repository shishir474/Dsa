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