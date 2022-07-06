
struct compare {
	bool operator()(struct Node* p1, struct Node* p2)
	{
		return p1->data > p2->data;
	}
};

// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
    if (head==NULL) return head;

    struct Node* st = NULL; // dummy node
    struct Node* tail= NULL;

	priority_queue<Node*, vector<Node*>, compare> pq;
    struct Node* t=head;
    while(t){
        pq.push(t);
        if(pq.size() > k){
            struct Node* top = pq.top(); pq.pop();
            if (st==NULL){
                st=top; 
                tail=top;
                st->prev = NULL;
            }
            else{
                tail->next= top;
                top->prev=tail;
                tail=tail->next;
            }
        }

        t=t->next;
    }

    while(!pq.empty()){
        tail->next = pq.top();
        pq.top()->prev = tail;
        tail = tail->next;
        pq.pop();
    }
    
    tail->next=NULL;
    
    return st;
}


Time Complexity: O(n*log k)
Auxiliary Space: O(k)