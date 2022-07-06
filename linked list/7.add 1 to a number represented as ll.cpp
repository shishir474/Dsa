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

Node* addOne(Node *head) 
{
    struct Node* reshead = rev(head);
    if(reshead->data < 9) reshead->data++;
    else{
        struct Node* t=reshead;
        t->data=0;
        t=t->next;
        int carry=1;
        while(t and carry>0){
            int sum=t->data+carry;
            t->data=sum%10;
            carry=sum/10;
            t=t->next;
        }
        
        if(carry > 0){
            struct Node* tail=reshead;
            while(tail->next) tail=tail->next;
            tail->next = new Node(1);
        }
    }
    
    return rev(reshead);
}