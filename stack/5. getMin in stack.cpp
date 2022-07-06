#include<iostream>
#include<stack>
using namespace std;

// Aaditya verma
class specialStack{
  stack<int> s,ss;  // s and supporting stack
  public:
  
  void push(int x){
    s.push(x);
    if(ss.size()==0 || x<=ss.top()){
        ss.push(x);
    }
  }
  
  int pop(){
    if (s.size()==0)
        return -1;
        
    int ans=s.top();
    s.pop();
    if(ss.top()==ans){
        ss.pop();
    }
    return ans;
  }
  
  int getMin(){
      if (ss.size()==0) return -1;
      return ss.top();
  }

};

int main(){
   
    specialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin();
}
