// Recursive sol.
void solve(stack<int>& s, int size, int current){
        if(current==size/2){
            s.pop(); return;
        }
        int top=s.top();
        s.pop();
        solve(s,size,current+1);
        s.push(top);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(s.empty()) return;
        else if(s.size()==1){
            s.pop();
            return;
        }
        solve(s,sizeOfStack,0);
    }



// Iterative sol.

void deleteMid(stack<char>& st)
{
	int n = st.size();
	stack<char> tempSt;
	int count = 0;
	// put first n/2 element of st in tempSt
	while (count < n / 2) {
		char c = st.top();
		st.pop();
		tempSt.push(c);
		count++;
	}
	// delete middle element
	st.pop();
	// put all (n/2) element of tempSt in st
	while (!tempSt.empty()) {
		st.push(tempSt.top());
		tempSt.pop();
	}
}