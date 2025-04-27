
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


// Solution 2        same solution, just different way of writing:

struct cmp{
    bool operator()(const Node* a, const Node* b){
        return a->data > b -> data;     // min heap use > 
    }
};
Node *sortedDll(Node *head, int k)
{
    priority_queue<Node*, vector<Node*>, cmp> pq;
    Node* curr = head;

    Node* start = new Node(-1);
    Node* tail = start;

    while(curr){
        if(pq.size() > k){
            Node* top = pq.top(); 
            // cout<<top->data<<endl;
            pq.pop();
            tail -> next = top;
            top -> prev = tail;     // it's a DLL, need to mark both next and prev pointers
            tail = top;
        }
        pq.push(curr);
        curr = curr->next;
    }

    while(!pq.empty()){
        Node* top = pq.top(); 
        // cout<<top->data<<endl;
        pq.pop();
        tail->next = top;
        top -> prev = tail;
        tail = top;
    }
    
    tail->next = NULL;
    Node* res = start->next;
    if(res) res->prev = NULL;

    return res;
}