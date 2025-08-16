Buy and Sell stocks with Cooldown 

Cooldown basically means you cannot buy right after sell.
There is a cooldown of 1 day 

stock problem 1--> one transaction
stock problem 2--> unlimited transactions
stock problem 3--> atmost 2 transactions
stock problem 4--> atmost k transactions

// This is the generic recurrence relation
solve(idx, buy){
    if(buy == true){
        // I'll buy stock or I'll skip this
        // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
        return max(-prices[idx] + solve(idx+1, 0), solve(idx+1, 1));
    } else {
        // I'll sell stock or I'll hold it. 
        // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
        return max(prices[idx] + solve(idx+1, 1), solve(idx+1, 0));
    }
}

//  TC: O(2^n) 
// SC: O(n) - auxilary stack space


// Now there is a small twist. We have a cooldown period of 1 day after selling. So we cannot buy right after selling hence i+2 in sell 
solve(idx, buy){
    if(buy == true){
        // I'll buy stock or I'll skip this
        // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
        return max(-prices[idx] + solve(idx+1, 0), solve(idx+1, 1));
    } else {
        // I'll sell stock or I'll hold it. 
        // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
        return max(prices[idx] + solve(idx+2, 1), solve(idx+1, 0));
    }
}


// Base case remains same 
if idx >= n return 0;   

-----------------------------------------------------------

// Recursion + memoisation (to avoid solving repeated subproblems)

    vector<int> arr;
    int t[5003][2];
    int solve(int idx, int buy){
        if (idx >= arr.size()) return 0;
        // adding memoisation
        if(t[idx][buy] != -1) return t[idx][buy];
        if(buy == true){
            // I'll buy stock or I'll skip this
            // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
            return t[idx][buy] = max(-arr[idx] + solve(idx+1, 0), solve(idx+1, 1));
        } else {
            // I'll sell stock or I'll hold it. 
            // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
            return t[idx][buy] = max(arr[idx] + solve(idx+2, 1), solve(idx+1, 0));
        }
    }


    int maxProfit(vector<int>& prices) {
        arr = prices;
        memset(t, -1, sizeof(t));
        // 0,1 because we are starting from 0th index and we would first need to buy 
        return solve(0, 1);
    }

// TC: O(n * 2)
// SC: O(n * 2) + O(n)
// O(n * 2) for dp array and O(n) for recursion stack space

-----------------------------------------------------------

Tabulation : Benefit of this is we get rid of auxilary stack space

int t[n+1][2];
t[n][0] = t[n][1] = 0;
for(int i = n-1; i >= 0; i--){
    for(int buy = 0; buy<=1; buy++){
        if(buy == true){
            // I'll buy stock or I'll skip this
            // If I buy stock I cannot buy in the future hence 0 and If I skip it I can buy in the future hence 1
            t[i][buy] = max(-arr[i] + t[i+1][0], t[i+1][1]);
        } else {
            // I'll sell stock or I'll hold it. 
            // If I sell stock I can buy in the future hence 1 and If I hold it I cannot buy in the future, hence 0
            t[i][buy] = max(arr[i] + t[i+2][1], t[i+1][0]);
        }
    }
}

return t[0][1];         
// NOTE: In the recusion+memo solution we return solve(0, 1);
// This state remains the same in tabulation. Hence we return t[0][1];

// TC: O(n * 2)
// SC: O(n * 2) 

-----------------------------------------------------------

-- Space optimisation:
We wont space optimise this because ith index depends on (i+1)th and (i+2)th index.
So we woud need to maintain 3 X 2 dp array. Maintaining 3 rows is not a very good solution. 
hence no space optimisation here.