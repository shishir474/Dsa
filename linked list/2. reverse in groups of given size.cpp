    struct node* reverseLL(struct node* head){
        struct node* t=head,*prev=NULL;
        while(t){
            struct node* next = t->next;
            t->next=prev;
            prev=t;
            t=next;
        }
        
        return prev;
    }
    
    
    struct node *reverseInGroupsOfK(struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL) return head;
        struct node* t=head,*prev=NULL;
        int c=0;
        while(t and c<k){
            prev = t;
            t = t->next; c++;
        }
        prev->next=NULL;
        struct node* thead =  reverse(t,k);
        struct node* res = reverseLL(head);
        head->next = thead;
        return res;
    }