    // Iterative O(N) time and O(1) space
    struct Node* t=head,*prev=NULL;
    while(t){
        struct Node* next = t->next;
        t->next = prev;
        prev = t;
        t = next;
    }
    
    return prev;



// Recursive
    if (head==NULL || head->next==NULL) return head;
    struct Node* tail = head->next;
    struct Node* res = reverseList(head->next);
    tail->next = head;
    head->next=NULL;
    return res;