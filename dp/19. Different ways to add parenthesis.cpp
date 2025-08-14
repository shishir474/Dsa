Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].



class Solution {
public:
    unordered_map<string, vector<int>> mp;      // for memmoisation

    vector<int> solve(string s){
        // check if result is already computed for this string
        if(mp.count(s)) return mp[s];

        int n = s.length();
        vector<int> res;

        bool operator_found = false;

        for(int k=0; k<n; k++){
            if(s[k]=='+' or s[k]=='-' or s[k]=='*'){
                operator_found = true;                          // to handle base condition
                // partitions - s[0..k-1] and [k+1..n-1]
                string s1 = s.substr(0,k);
                string s2 = s.substr(k+1);

                // get the results for both partitions
                vector<int> t1 = solve(s1);
                vector<int> t2 = solve(s2);
                
                // generate all possible answers
                if (s[k] == '+'){
                    for(auto val1: t1){
                        for(auto val2: t2){
                            res.push_back(val1 + val2);
                        }
                    }
                }
                else if(s[k] == '-'){
                    for(auto val1: t1){
                        for(auto val2: t2){
                            res.push_back(val1 - val2);
                        }
                    }
                }
                else if(s[k] == '*'){
                    for(auto val1: t1){
                        for(auto val2: t2){
                            res.push_back(val1 * val2);
                        }
                    }
                }

            }
        }

        if(operator_found == false){
            res.push_back(stoi(s));      // convert string to integer using stoi(s) and return
        }

        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        mp.clear();         // clear the map before each call
        return solve(expression);
    }
};

// Time and Space complexity 
The time complexity of this code is O(n³), where n is the length of the input string.

Explanation:

For each operator in the string (up to n), you recursively partition the string into two parts.
There are O(n²) unique substrings (memoized).
For each substring, you may combine up to O(n) results from left and right partitions.
So, overall: O(n³).
Space complexity: O(n²) (for memoization map and recursion stack).


When you split a substring at an operator, you recursively compute all possible results for the left and right partitions.
Suppose for a substring s, you split at position k:

The left partition (s1 = s[0..k-1]) may have multiple possible results (let's say L results).
The right partition (s2 = s[k+1..n-1]) may also have multiple possible results (let's say R results).
To generate all possible results for the current split, you need to combine every result from the left with every result from the right using the operator at position k.
This means you do L * R combinations for this split.
Since the number of possible results for any substring can be up to O(n) (in the worst case, due to different ways of parenthesizing),
for each substring and each split, you may need to combine up to O(n) results from the left and O(n) results from the right, resulting in O(n²) combinations for that split

// According to me the TC should be O(n^4)