
Given 1->2->3->3->4->4->5, return 1->2->3->4->5.

Node *removeDuplicates(Node *head)
{
  struct Node* t=head;
    while(t){
        struct Node* p=t->next;
        while(p and p->data==t->data) p=p->next;
        t->next=p;
        t=p;
    }
    return head;
}






  INTERVIEW BIT PROBLEM:


Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 cases to think of:
  1 1 1 1 1
  1 1 2 2 
  1 2 3 4 5
  
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* start = new ListNode(-1);
    start->next=A;
    ListNode* t=A,*prev=start;
    while(t){
        if(t->next and t->val != t->next->val){
            prev=t;
            t=t->next;
        }
        else{
            if(t->next==NULL) break; // if all elements distinct
            ListNode* b=t->next;
            while(b and b->val==t->val)b=b->next;
            prev->next=b;
            t=b;
        }
    }
    
    return start->next;
}
