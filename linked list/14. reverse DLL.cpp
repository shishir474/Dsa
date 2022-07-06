Node* reverseDLL(Node * head)
{
    Node* curr=head,*prev=NULL;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}
