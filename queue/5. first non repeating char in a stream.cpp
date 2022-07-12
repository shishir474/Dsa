First non-repeating character in a stream

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'


solution;
ek map maintain kro to maintain freq, and ek queue rakhio. IF qiueue ke front pe repeating char hai ya non repeating. If repeating hai toh pop krdo hume voh chahiye hi nai nai toh print krado
If queue hi empty hogai to koi non repeating char hai hi nai toh usme # print krado


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