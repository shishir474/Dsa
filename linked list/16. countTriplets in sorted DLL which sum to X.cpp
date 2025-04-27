#include <bits/stdc++.h> 
/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int getLength(DLLNode* head){
    DLLNode* t=head;
    int len=0;
    while(t){
        len++;
        t=t->next;
    }
    return len;
}

int countTriplets(DLLNode* head, int x)
{
    if(head == NULL) return 0;
    
    int cnt = 0;
    
    DLLNode* temp = head;
    while(temp->next) temp = temp->next;
    // temp points to your tail node

    int len = getLength(head);
    DLLNode* t1 = head;
    int i = 0;
    while(t1 and i < len-2){
        DLLNode* t2= t1->next, *t3 = temp;
        while(t2 and t3 and t2 != t3 and t2->prev != t3){      // in arrays, ensuring t2 < t3 is easy, but in linked lists the same can be represented via the conditions t2->prev != t3
            int sum = t1->data + t2->data + t3->data;
            if(sum == x){
                cnt++;          // found 1 pair
                t2 = t2->next;  // since list contains unique elements, update t2 and t3
                t3 = t3->prev;
            }
            else if(sum < x){       // we need to increase the sum
                t2 = t2->next;
            }
            else{       // we need to decrease the sum 
                t3 = t3->prev;
            }
        }
        i++;
        t1 = t1->next;
    }

    return cnt;
}  