  Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
bool isPalindrome(Node *head)
{    
// ITERATIVE:
    // find the middle element and reverse the later half and compare both the lists
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* h1 = reverse(slow);
    Node* h2 = head;
    while(h1!=NULL){
        if (h1->data != h2->data)
        return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return true;
}




// recursive sol.
 bool isPalindrome(Node *head){
    if (head == NULL || head->next == NULL)
        return true;
    
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev  =temp;
        temp = temp->next;
    }
    if (head->data != temp->data)
    return false;
    prev->next = NULL;
    head = head->next;
    
    return isPalindrome(head);
 }
 