Reverse a stack without using extra space in O(n)

Reverse a Stack without using recursion and extra space. Even the functional Stack is not allowed.

Examples:  

Input : 1->2->3->4
Output : 4->3->2->1

Input :  6->5->4
Output : 4->5->6

// solution
We can reverse a stack in O(1) space/without recursion if we internally represent the stack as 
a linked list. Reverse a stack would require a reversing of a linked list which can be done 
with O(n) time and O(1) extra space.
Note that push() and pop() operations still take O(1) time

TC: for reversing a Linked list is O(n). Since we have implemented stack as linked list, reversing stack requires reversing the list which is O(n)
SC; O(1), no extra space used ignoring the nodes

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

// Linked list implementation of stack
class myStack{
    struct Node* head;
    int cnt;
    
    public:
    myStack(){
        head = NULL;
        cnt=0;
    }
    
    void push(int x){
        struct Node* nn = new Node(x);
        if(head==NULL){
            head = nn;
            cnt=1;
            return;
        }
        nn->next = head;
        head = nn;
        cnt++;
    }
    
    void pop(){
        if(head==NULL){
            cout<<"stack underflow"<<endl;
            return;
        }
        head = head->next;
        cnt--;
    }
    
    int top(){
        if(head==NULL) return -1;
        return head->val;
    }
    
    int size(){
        return cnt;
    }
    
    bool isEmpty(){
        return cnt==0;
    }
    
    void reverse(){
        struct Node* t = head, *prev=NULL;
        while(t){
            struct Node* next = t->next;
            t->next = prev;
            prev= t;
            t = next;
        }
        // update head to prev as prev is new head
        head = prev;
    }
    
    void print(){
        struct Node* t = head;
        while(t){
            cout<<t->val<<" ";
            t=t->next;
        }
    }
};

int main(){
 myStack s;
 s.push(1);
 s.push(2);
 s.push(3); 
 s.push(4);
 s.push(5);
 
 s.reverse();
 
 s.print();
    
 

}