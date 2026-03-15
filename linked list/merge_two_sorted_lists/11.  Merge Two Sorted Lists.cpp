 Merge Two Sorted Lists

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* st=new ListNode(-1);  // dummy node
    ListNode* tail=st;
    ListNode* t1=list1, *t2=list2;
    while(t1 && t2){
        if (t1->val < t2->val){
            tail->next = t1;
            t1=t1->next;
            tail =  tail->next;
        }
        else{
            tail->next = t2;
            t2=t2->next;
            tail =  tail->next;
        }
    }
    
    if(t1) tail->next = t1;
    if(t2) tail->next=t2;
    
    return st->next;
}