#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *quickSortLL(Node *head)
{
	if(head == NULL or head->next == NULL) return head;

	// considering last node as the pivot
	Node* pivot = head;
	while(pivot->next){
		pivot = pivot->next;
	}

	// created 2 dummy nodes to track the list smaller than and larger than pivot
	Node* start1 = new Node(-1);	// l1 contains values <= than pivot 
	Node* tail1 = start1;
	Node* start2 = new Node(-1);	// l2 contains value > pivot
	Node* tail2 = start2;

	// process nodes of the orig list and add it to l1 or l2 depending on it's value compared to the pivot element
	Node* curr = head;
	while(curr != pivot){
		if(curr->data <= pivot->data){
			tail1->next = curr;
			tail1 = curr;
		}
		else{
			tail2->next = curr;
			tail2 = curr;
		}
		curr = curr->next;
	}
	tail1->next = NULL;		// mark the end of the l1
	tail2->next = NULL;		// mark the end of l2
	
	// recurse on l1 and l2 
	Node* head1 = quickSortLL(start1->next);
	Node* head2 = quickSortLL(start2->next);

	// final ans = l1 + pivot + l2
	// Note: l1 and l2 are lists, so first find the tail of l1(can't use tail1, since it was the tail in the unsorted list, after sorting the tail would change)
	// append pivot to l1's tail 
	// and then append l2's head next to pivot

	// edge case: if l1's head is null, it's tail doesn't exist, In that case, append l2's head next to pivot and pivot will be the head of your final sorted list
	if(head1==NULL){
		pivot->next = head2;
		return pivot;
	}

	// finding l1's tail
	Node* tail = head1;
	while(tail->next) tail = tail->next;
	
	// append pivot to l1's tail
	tail->next = pivot;
	// append l2's head to pivot
	pivot->next = head2;

	// return l1's head
	return head1;


}