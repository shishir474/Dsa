Node *removeDuplicates(Node *head)
{
  struct Node* t=head;
    while(t){
        struct Node* p=t->next;
        while(p and p->data==t->data) p=p->next;
        t->next=p;
        t=p;
    }
    return head;
}