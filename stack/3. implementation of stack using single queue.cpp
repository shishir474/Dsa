#include<iostream>
#include<queue>
using namespace std;
 
class myStack{
  queue<int> q1;

  public:
  void push(int x){
    q1.push(x);
    for(int i=0;i<q1.size()-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
  }
  
  int pop(){
      if(q1.empty()) return -1;
      int ans = q1.front();
      q1.pop();
      return ans;
  }
  
  bool isEmpty(){
      return q1.empty();
  }
  int peek(){
      if(q1.empty()) return -1;
      return q1.front();
  }
  int size(){
      return q1.size();
  }
};
int main(){
    myStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    while (!s.isEmpty()){
        cout<<s.peek()<<endl;
        s.pop();
    }
}
