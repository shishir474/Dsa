#include <iostream>

using namespace std;

class myQueue{
  int* a;
  int front,rear,cnt,maxsize;
  
  public:
  myQueue(int size){
      a = new int[size];
      maxsize=size;
      front=0;rear=0;cnt=0;
  }
  
  void push(int x){
      if(cnt==maxsize){
          cout<<"Queue is full"<<endl;
          return;
      }
      a[rear%maxsize] = x;
      rear++;
      cnt++;
  }
  
  void pop(){
      if(cnt==0){
          cout<<"Queue is empty"<<endl;
          return;
      }
      a[front%maxsize] = -1; // putting some dummmy data at front
      front++;
      cnt--;
  }
  
  int peek(){
      if(cnt==0){
          return -1;
      }
      return a[front];
  }
  
  bool isEmpty(){
      return cnt==0;
  }
  
  int size(){
      return cnt;
  }
  
  void printQueue(){
      if(cnt==0){
          cout<<"queue is empty"<<endl;
          return;
      }
      
      for(int i=front;i<rear;i++){
        cout<<a[i%maxsize]<<" ";
      }
      cout<<endl;
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