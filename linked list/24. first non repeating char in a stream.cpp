First non-repeating character in a stream

input="hcczah"
output="hhhhhz"

input="aabc"
output="a#bb"

input="zz"
output="z#"


sol1: Using map

string FirstNonRepeating(string A){
        map<char,pair<int,int>> mp;
        string ans="";
        for(int i=0;i<A.length();i++){
            if(mp.count(A[i])==0){
                mp[A[i]] = {1,i}; // store the first occurence
            }
            else{
                mp[A[i]].first++;
            }
            char ch='#';
            int idx=INT_MAX;
            for(auto i: mp){ // only single occurence wala char will be considered
                if(i.second.first==1 and i.second.second<idx){
                    ch = i.first;
                    idx=i.second.second;
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }

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