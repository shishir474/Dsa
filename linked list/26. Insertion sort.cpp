Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // https://www.youtube.com/watch?v=CPAWcc78IB4
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* start = new ListNode(-1);
    start->next=A;
    ListNode* prev=start,*curr=A;
    while(curr){
        if(curr->next and curr->val < curr->next->val) curr=curr->next;
        else{
            if(curr->next==NULL) break;
            while(prev->next and prev->next->val < curr->next->val) prev=prev->next;
            ListNode* t=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=t;
            prev=start;
        }    
    }
    
    return start->next;
}
