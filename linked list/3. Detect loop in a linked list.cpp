bool detectLoop(Node* head)
{
    // your code here
    struct Node* slow=head,*fast=head;
    while(slow and fast and fast->next){
        slow = slow->next; 
        fast=fast->next->next;
        if (slow==fast) return true;
    }
    return false;
}