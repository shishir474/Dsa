Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters

Note: While forming a word we can move to any of the 8 adjacent cells. A cell can be used only once in one word.


Example 1:

Input: 
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation: 
C A P
A N D
T I E
Words we got is denoted using same color.
Example 2:

Input:
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3 
board = {{G,I,Z},{U,E,K},{Q,S,E}}
Output:
GEEKS QUIZ
Explanation: 
G I Z
U E K
Q S E 
Words we got is denoted using same color.

TC: O(m*n*number_of_words)+O(8*length_of_longest_string*number_of_words)
int X[8]={-1,-1,0,1,1,1,0,-1};
int Y[8]={0,1,1,1,0,-1,-1,-1};

    bool search(int i, int j, vector<vector<char> >& board, string s, int idx){
        if(idx>=s.length()) return true;
     
        char ch=board[i][j];
        board[i][j]='$';
        
        bool ans=false;
        
        for(int k=0;k<8;k++){
            int newi=i+X[k], newj=j+Y[k];
            if(newi>=0 and newi<board.size() and newj>=0 and newj<board[0].size() and board[newi][newj]==s[idx]){
                if(search(newi,newj,board,s,idx+1)){
                    ans= true; break;
                }
            }
        }
      
        board[i][j]=ch;
        return ans;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& d) {
	    int n=board.size(), m=board[0].size();
	    vector<string> res;
	    
	    sort(d.begin(),d.end());
	    
	    for(int k=0;k<d.size();k++){
	        string s=d[k];
	        int f=0;
	        for(int i=0;i<board.size();i++){
	            for(int j=0;j<board[0].size();j++){
	                if(board[i][j]==s[0] and search(i,j,board,s,1)){
	                    res.push_back(s); f=1; break;
	                }
	            }
	            if(f) break;
	        }
	        
	        
	    }
	    
	    return res;
	}