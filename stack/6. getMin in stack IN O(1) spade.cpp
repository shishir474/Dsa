#include<bits/stdc++.h>
#include<stack>
using namespace std;

// Aaditya verma video solution:
class specialStack{
  stack<int> s;
  int minEle;
  public:
  void push(int x){
    if (s.size()==0){
        s.push(x);
        minEle = x;
    }
    else{
        if (x>=minEle){
            s.push(x);
        }
        else if(x < minEle){
            s.push(2*x - minEle);
            minEle = x;
        }
    }
  }
  
  int pop(){
    if (s.empty()) return -1;
    if (s.top()>=minEle) 
        s.pop();
    else{
        minEle = 2*minEle - s.top();
        s.pop();
    }
  }
  
  int top(){
      if(s.empty()) return -1;
      if(s.top() < minEle) return minEle;
      else return s.top();
  }
  
  int getMin(){
      if (s.size()==0) return -1;
      return minEle;
  }

};

int main(){
   
    specialStack s;
 
    vector<int> arr = { 3, 2, 6, 1, 8, 5, 5, 5, 5 };
 
    for(int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
        cout<<s.getMin()<<endl;
    }

     
    cout << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        s.pop();
        cout<<s.getMin()<<endl;
    }
    return 0;
}
