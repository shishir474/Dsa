First non-repeating character in a stream

input="hcczah"
output="hhhhhz"

input="aabc"
output="a#bb"

input="zz"
output="z#"


sol1: Using map

string Solution::solve(string A) {
    string res = "";
    map<char,pair<int,int>> mp;     // last_pos of char, freq
    for(int i=0;i<A.length();i++){
        char c = A[i];
        // if not unique char, update its last position, and increase the freq 
        if(mp.count(c)) {mp[c].first = i; mp[c].second++;}
        else mp[c] = {i,1};
        
        int min_idx = INT_MAX;
        for(auto i: mp){        
            if(i.second.second == 1 and i.second.first < min_idx) {
                min_idx = i.second.first;
            }
        }
        if(min_idx == INT_MAX) res.push_back('#');
        else res.push_back(A[min_idx]);
    }
            
    return res;
}


// IN the worst case,  since the string only contains unique char, the map size will not exceed 26
// Thus during each iteration, we can easily iterate over the map, It will not be a linear operation, since we have at max 26 keys in the map 
// Thus this will take constant time 

// We are only concerned with char whose freq is 1. 
// One imp thing about maps in cpp is they store the keys in the lexicographical order, not in the order in which they are inserted 
// so in order to pick the first char in the string, we'll also need to track the position of the char in the map, hence using map<char, pii>
// s = "ie"
// if you dont track the position of char in map, you will get ie, but the correct ans is ii
// first unique char in "ie" is still i. How did we know that it was the first char. We tracked the positions in the map
// So we'll only check those keys whose freq is 1 and we will calculate the min_idx. This min_idx will ensure that we're always picking the first non repeating char 



    TC: O(n*26), sc: O(26); at max map will contain 26 keys









sol2. USING DLL

maintain two arrays: one array is to maintain characters that are already visited two or more times, we call it repeated[], the other array is an array of pointers to linked list nodes, we call it inDLL[]. The size of both arrays is equal to alphabet size which is typically 256.


Create an empty DLL. Also, create two arrays inDLL[] and repeated[] of size 256. In DLL is an array of pointers to DLL nodes. repeated[] is a boolean array, repeated[x] is true if x is repeated two or more times, otherwise false. inDLL[x] contains a pointer to a DLL node if character x is present in DLL, otherwise NULL.
Initialize all entries of inDLL[] as NULL and repeated[] as false.
To get the first non-repeating character, return character at the head of DLL.
Following are steps to process a new character 'x' in a stream. 
If repeated[x] is true, ignore this character (x is already repeated two or more times in the stream)
If repeated[x] is false and inDLL[x] is NULL (x is seen the first time). Append x to DLL and store address of new DLL node in inDLL[x].
If repeated[x] is false and inDLL[x] is not NULL (x is seen a second time). Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] as NULL and repeated[x] as true.

Note that appending a new node to DLL is O(1) operation if we maintain a tail pointer. Removing a node from DLL is also O(1). So both operations, addition of new character and finding first non-repeating character take O(1) time.




class node{
        public:
        char data;
        node* next,*prev;
        node(char ch){
            data=ch;
            next=NULL;
            prev=NULL;
        }
    };
    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        
        if(delnext)
        delnext->prev=  delprev;
    }
    
    string FirstNonRepeating(string A){
        vector<node*> dll(26,NULL);
        vector<bool> vis(26,false);
        
        node* dhead = new node('\0');
        node* tail=dhead;
        string ans="";
        
        for(int i=0;i<A.length();i++){
            int index=A[i]-'a';
            if(!vis[index]){
                if(dll[index]==NULL){ // first time 
                    node* n = new node(A[i]);
                    tail->next=n;
                    n->prev=tail;
                    tail=tail->next;
                    dll[index]=n;
                }
                else{  // second time
                    node* delnode=dll[index];
                    if(delnode == tail) // if the node to be deleted is the last node thn update tail otherwise tail remaoins unaffected
                    tail=tail->prev;
                    
                    deleteNode(delnode);
                    dll[index]=NULL;
                    vis[index]=true;
                }
            }
            char ch='#';
            if(dhead->next) ch=dhead->next->data;
            ans.push_back(ch);
            
        }
        
        
        return ans;
        
    }

    
    
    
    solution 3: Using queue
  
  	// intuition:
	/// usi order me characters chahei -> queue use krne padegi
	// first non repeating char means jiski freq 1 hai, so hume freq store kren padegi, so we can use arrya 26 size ka or map
	string FirstNonRepeating(string A){
        queue<char> q; 
        map<char,int> mp;
        string res="";
        
        for(int i=0;i<A.length();i++){
            mp[A[i]]++;
            q.push(A[i]);
            while(!q.empty() and mp[q.front()] > 1){
                q.pop();
            }
            if(q.empty()) res.push_back('#');
            else res.push_back(q.front());
            
        }
        
        return res;
	}