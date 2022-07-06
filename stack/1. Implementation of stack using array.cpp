#include<iostream>
using namespace std;
 
class myStack{
  public:
  int maxSize;
  int top;
  int* a;
  
  myStack(int size){
      maxSize = size;
      top = -1;
      a = new int[maxSize];
  }
  
  void push(int element){
      if (top == maxSize-1){
          cout<<"stack is full can't add more elements"<<"\n";
          return;
      }
      top = top+1;
      a[top] = element;
  }
  
  int pop(){
      if (top==-1){
          cout<<"stack is empty"<<"\n";
          return -1;
      }
      int ans = a[top];
      top--;
      return ans;
  }
  
  bool isEmpty(){
      return top==-1;
  }
  int peek(){
      if (top==-1){
          cout<<"Stack is empty"<<"\n";
          return -1;
      }
      return a[top];
  }
  int size(){
      if (top==-1) return 0;
      return top+1;
  }
};
int main(){
    myStack s(5);
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
