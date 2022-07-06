Intersection of Two Linked Lists
1->9->1->2->4
3->2->4
ans: intersected at 2

 int length(ListNode* head){
    ListNode* t=head;
    int len=0;
    while(t){
        len++;
        t=t->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1=length(headA),len2=length(headB);
    if (len1<len2){
        ListNode* t1=headA,*t2=headB;
        int val=len2-len1;
        while(val>0){
            t2=t2->next;
            val--;
        }
        while(t1!=t2){
            t1=t1->next; 
            t2=t2->next;
        }
        return t1;
    }
    else{
        ListNode* t1=headA,*t2=headB;
        int val=len1-len2;
        while(val>0){
            t1=t1->next;
            val--;
        }
        while(t1!=t2){
            t1=t1->next; 
            t2=t2->next;
        }
        return t1;
    }
        
}