original list: 4 6 1 5 10 8 4 2
modified list: 1 6 4 8 10 5 2 4


struct Node* reverseDLL(struct Node* head){
    struct Node* c=head,*p=NULL;
    while(c){
        struct Node* next = c->next;
        c->next = p;
        c->prev = next;
        p=c;
        c=next;
    }

    return p;
}
// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	if (head==NULL) return NULL;  // base case

    struct Node* t=head;
    int c=0;
    while (c<k and t)
    {
       c++;
       t=t->next;
    }
    if (t){  // check required
        t->prev->next=NULL;  
        t->prev=NULL;
    }
    struct Node* res=reverseDLL(head);
    struct Node* tail=res;
    while(tail->next) tail=tail->next;
    struct Node* thead = revListInGroupOfGivenSize(t,k);  // calling recursion
    tail->next = thead;
    if(thead) thead->prev = tail;  // check required
    return res;
}