Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* reverse(ListNode* head){
     ListNode* t=head,*prev=NULL;
     while(t){
         ListNode* next=t->next;
         t->next=prev;
         prev=t;
         t=next;
     }
     return prev;
 }
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode* t2=A,*prev=NULL;
    int c=0;
    while(t2 and c<n){
        c++;
        prev=t2;
        t2=t2->next;
    }
    
    prev->next=NULL;
    
    ListNode* t1=A,*prev2=NULL;
    c=0;
    while(t1 and c<m-1){
        c++;
        prev2=t1;
        t1=t1->next;
    }
    
    ListNode* ans = A;
    
    if(prev2)
    prev2->next= reverse(t1);
    else
    ans = reverse(t1);
    
    t1->next =  t2;
    
    return ans;
  
    
}
