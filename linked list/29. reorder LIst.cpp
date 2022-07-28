Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* merge(ListNode* A, ListNode* h2){
     ListNode* head = new ListNode(0);
     ListNode* start = head;
     int c=0;
     ListNode* t1 = A, *t2= h2;
     while(t1!=NULL || t2!=NULL){
         c++;
         if (c%2 == 1){
             start->next = t1;
             t1 = t1->next;
         }
         else{
             start->next = t2;
             t2 = t2->next;
         }
         start = start->next;
     }
     return head->next;
 }

 ListNode* reverse(ListNode* h){
     ListNode* curr = h, *prev = NULL;
     while(curr){
         ListNode* next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }
     return prev;
 }

ListNode* Solution::reorderList(ListNode* A) {
    if (A==NULL) return A;

    // 1->2->3->4->5->NULL   => 1->5->2->4->3->NULL
    // 1->2->3  split at the middle and reverse the latter half, Then merge the two lists
    // 5->4
    // Now merge the above two list
    ListNode* slow = A, *fast = A->next;  // Even length - first middle should be the middle element. Hence initialised fast with head->next. If u want the second middle, then initialise fast with head
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* h2= slow->next;
    slow->next = NULL;
    ListNode* h2rev =  reverse(h2);
    return merge(A, h2rev);

}
