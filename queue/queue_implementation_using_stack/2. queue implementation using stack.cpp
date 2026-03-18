#include <iostream>

using namespace std;

solution 1:
push()
take two stacks s1 and s2, first transfer all the elements of s1 to s2, insert then into s1 and then again transfer all elements of s2 to s1
TC of push() is O(n)
pop() is O(1) 
peek() is o(1)

can we doo something better. Yes we can
amortised TC of push() and pop() is O(1)

solution 2:

class myQueue{
  stack<int> input,output;
  
  public:
  
  //TC: push and pop have amortised tc of O(1).  pop operation is O(n) but its true for very few instances. IN most of the cases it is O(1), same for peek().
  // sc: O(2*n)
  void push(int x){
    input.push(x);
  }
  
  void pop(){
    if(!output.empty()) 
        output.pop();
    else{
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        if(output.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        output.pop();
    }
  }
  
  int peek(){
      if(!output.empty())
        return output.top();
      else{
         while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        if(output.empty()){
            return -1;
        }
        output.top();
      }
  }
  
  bool isEmpty(){
     return input.empty() and output.empty();
  }
  
  int size(){
      return input.size()+output.size();;
  }
  
  void printQueue(){
    // first print output stack and then print input stack in reverse manner to print the queue 
  }
  
};

int main()
{
    myQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(6);
    q.printQueue();
    
    
    
    return 0;
}