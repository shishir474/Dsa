Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :
Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.

solution 1: divide the array into k parts for each stack. but this is not space efficienct. coz let say array dedicated for stack 2 is full but there is empty space in the array.
Despite having empty space in the array we wont be able to add element in stack 2


// solution 2:
TC;O(1), SC:O(1)

#include <bits/stdc++.h>
class NStack
{
    int* a;
    int* top;
    int* next;
    int freespot;
    int n,s;
    
public:
    // implement N stacks in S sized array
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n=N;
        s=S;
        a = new int[S];
        top = new int[N];
        next= new int[S];
        for(int i=0;i<N;i++){
            top[i]=-1;
        }
        for(int i=0;i<S;i++){
            next[i] = i+1;
        }
        // update last next index
        next[S-1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot==-1) return false; 
        
        // find index
        int index = freespot;
        
        // update freespot
        freespot = next[index];
        
        // insert elemnent into array
        a[index] = x;
        
        //update next
        next[index] = top[m-1];
        
        // update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1) return -1;
        
        // exact reverse of push 
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return a[index];
    }
};