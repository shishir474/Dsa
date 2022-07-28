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


TC: O(n^3) where n is the string length
SC: O(n^2) // n^2 calls 

class Solution {
public:
    
    // unordered_map was giving compile error dont wknow why, hence used map
    map<pair<int,int>, vector<int>> mp;
    
    bool isOperator(char ch){
        if(ch=='+' || ch=='-' || ch=='*') return true;
        return false;
    }
    
    bool noOperator(string s, int i, int j){
        for(int k=i;k<=j;k++){
            if(isOperator(s[k])) return false;
        }
        return true;
    }
    
    vector<int> solve(string s, int i, int j){
        vector<int> res;

// Base case: if the string contains no operator
        if(noOperator(s,i,j)){
            res.push_back(stoi(s.substr(i,j-i+1)));
            return mp[{i,j}] = res;
        }
    // check if already precomputed
         if(mp.count({i,j})==1){
            return mp[{i,j}];
        }
        
    // string can contain double digit no. two. Gist is we have to perfrom partition at operator.         
        for(int k=i;k<=j;k++){
            if(isOperator(s[k])){
                
                vector<int> left=solve(s,i,k-1);
                
                vector<int> right=solve(s,k+1,j);
                
                if(s[k]=='+'){
                    for(int a=0;a<left.size();a++){
                        for(int b=0;b<right.size();b++){
                            res.push_back(left[a]+right[b]);
                        }
                    }
                }
                else if(s[k]=='-'){
                    for(int a=0;a<left.size();a++){
                        for(int b=0;b<right.size();b++){
                            res.push_back(left[a]-right[b]);
                        }
                    }
                }
                else if(s[k]=='*'){
                    for(int a=0;a<left.size();a++){
                        for(int b=0;b<right.size();b++){
                            res.push_back(left[a]*right[b]);
                        }
                    }
                }
            
            }
        }
        
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        mp.clear();
        return solve(s,0,s.length()-1);
    }
};