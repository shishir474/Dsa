  struct Node* detectLoop(Node* head)
    {
        // your code here
        struct Node* slow=head,*fast=head;
        while(slow and fast and fast->next){
            slow = slow->next; 
            fast=fast->next->next;
            if (slow==fast) return slow;
        }
        return NULL;
    }
    
    void removeLoop(Node* head)
    {
        struct Node* slow = detectLoop(head);
        if(slow){
            struct Node* fast=head;
            while(slow != fast){
                slow=slow->next; fast=fast->next;
            } 
            // now slow is the entry point of the loop
            struct Node* t=slow->next;
            while(t->next != slow) t=t->next;
            t->next=NULL;
            
        }
    }