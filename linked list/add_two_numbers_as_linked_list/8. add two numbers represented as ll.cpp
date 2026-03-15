struct Node* rev(struct Node* head){
    struct Node* t=head,*prev=NULL;
    while(t){
        struct Node* next = t->next;
        t->next = prev;
        prev = t;
        t = next;
    }
    
    return prev;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    struct Node* st=new Node(-1); // dummy node
    struct Node* tail = st;
    struct Node* t1=rev(first), *t2=rev(second);
    int carry=0;
    while(t1 || t2){
        int sum=carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        tail->next = new Node(sum%10);
        tail=tail->next;
        carry=sum/10;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    
    if (carry > 0){
        tail->next = new Node(1);
        tail=tail->next;
    }
    
    return rev(st->next);
}