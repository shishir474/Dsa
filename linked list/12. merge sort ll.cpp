ListNode* getMid(ListNode* head){
    ListNode* slow=head,*fast=head,*prev=NULL;
    while(slow and fast and fast->next){
        prev = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    return slow;
}


ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
    if (t1==NULL) return t2;
    else if(t2==NULL) return t1;
    
    ListNode* res=NULL;
    if(t1->val < t2->val){
        res = t1;
        res->next = mergeTwoLists(t1->next,t2);
    }
    else{
        res = t2;
        res->next = mergeTwoLists(t1,t2->next);
    }
    
    return res;
}


ListNode* sortList(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;
    ListNode* mid = getMid(head);
    ListNode* t1 = sortList(head);
    ListNode* t2 = sortList(mid);
    return mergeTwoLists(t1,t2);
}