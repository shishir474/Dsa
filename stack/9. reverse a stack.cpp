Time Compleixty: In the worst case there wiil be n recursive calls & fr each call O(N) insert op is perfromed
Hence overall TC is O(n^2);
T(n)=  t(n-1)+O(n);
problem reduces to n-1 size and insert function has O(n)
Space complecity: o(n); for the stack

same complexity for sort stack problem


#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int ele){
    if(s.size()==0){
        s.push(ele);
        return;
    }
    int top=s.top(); s.pop();
    insert(s,ele);
    s.push(top);
}
`
void reverseUtil(stack<int>& s){
    if(s.size()==0) return;
    int top = s.top(); s.pop();
    reverseUtil(s);
    insert(s,top);
}

int main(){
 stack<int> s;
 s.push(1);
 s.push(2);
 s.push(3); 
 s.push(4);
 s.push(5);
 
 reverseUtil(s);
 while(!s.empty()){
     cout<<s.top()<<" ";
     s.pop();
 }
 

}

Sort the stack: Same problem 