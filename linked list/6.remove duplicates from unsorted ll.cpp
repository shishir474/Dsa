//Function to remove duplicates from unsorted linked list.
Node * removeDuplicates( Node *head) 
{
    // your code goes here
        if (head==NULL) return NULL;
        
        set<int> s;
        struct Node* fh=head,*ft=head;
        struct Node* t=head->next;
        s.insert(head->data);
        
        while(t){
            if(s.count(t->data)==0){
                ft->next=t;
                ft=ft->next;
                s.insert(t->data);
            }
            t=t->next;
        }
        
        ft->next=NULL;
        return fh;
    
}