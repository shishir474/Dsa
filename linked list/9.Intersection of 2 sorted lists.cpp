Given two lists sorted in increasing order, 
create a new list representing the intersection of the two lists.

L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.


Node* findIntersection(Node* head1, Node* head2)
{
    struct Node* st = new Node(-1); // dummy node
    struct Node* tail = st;
    struct Node* t1=head1,*t2=head2;
    while(t1 && t2){
        if(t1->data==t2->data){
            tail->next = new Node(t1->data);
            tail=tail->next;
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->data < t2->data){
            t1=  t1->next;
        }
        else{
            t2=t2->next;
        }
    }
    
    return st->next;
}