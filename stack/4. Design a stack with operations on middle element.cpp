How to implement a stack which will support the following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
Push and pop are standard stack operations. 

Method 1:
The important question is, whether to use a linked list or array for the implementation of the stack? 
Please note that we need to find and delete the middle element. Deleting an element from the middle is not O(1) for the array. Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In a singly linked list, moving the middle pointer in both directions is not possible. 
The idea is to use a Doubly Linked List (DLL). We can delete the middle element in O(1) time by maintaining mid pointer. We can move the mid pointer in both directions using previous and next pointers. 
Following is implementation of push(), pop() and findMiddle() operations. If there are even elements in stack, findMiddle() returns the second middle element. For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3. 
 


#include<iostream>
#include<queue>
using namespace std;
 
struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
    Node(int data){
        val = data;
        next=NULL;
        prev=NULL;
    }
};

class myStack{
    struct Node* head;
    struct Node* mid;
    int size;

  public:
  myStack(){
      head = NULL;
      mid = NULL;
      size = 0;
  }
  
  void push(int x){
    struct Node* t = new Node(x);
    if(size==0){
        head = t;
        mid = t;
    }
    else{
        head->next= t;
        t->prev = head;
        head = head->next;
        if(size%2){
            mid = mid->next;
        }
    }
    size++;
  }
  
  int pop(){
    if (size==0) return -1;
    int ans=head->val;
    if (size==1){
        head=NULL;
        mid=NULL;
    }
    else{
        head = head->prev;
        head->next = NULL;
        if(size%2 == 0){
            mid = mid->prev;
        }
    }
    size--;
    return ans;
  }
  
  int findMiddle(){
      if(size==0) return -1;
      return mid->val;
  }
  
  void deleteMiddle(){
      if (size==0){
          cout<<"NO middle element exists. stack is empty"<<endl;
          return;
      }
      if (size==1){
          head=NULL;
          mid=NULL;
      }
      else if(size==2){
          head=head->prev;
          mid=mid->prev;
          head->next=NULL;
      }
      else{
          mid->prev->next = mid->next;
          mid->next->prev = mid->prev;
          if (size%2)
              mid = mid->next;
          else
              mid = mid->prev;
      }
      size--;
  }
  
};

int main(){
   
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}
