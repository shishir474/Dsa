5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
Output:  5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50.


// Solution 1: Using Priority Queue(min heap)

struct cmp{
	bool operator()(const Node* a, const Node* b){
		return a->data > b -> data;				// min heap comparator
	}
};
Node* flattenLinkedList(Node* head) 
{
	Node* start = new Node(-1);
	Node* tail = start;

	// priority_queue<Node*, vector<Node*>, cmp> pq;
	priority_queue<Node*, vector<Node*>, cmp> pq;

	Node* curr = head;
	while(curr){
		pq.push(curr);
		// cout<<curr->data<<endl;
		curr = curr->next;
	}

	while(!pq.empty()){
		Node* top = pq.top();
		// cout<<top->data<<endl;
		pq.pop();
		tail -> child= top;
		tail->next = NULL;
		tail = tail->child;
		if(top->child){
			pq.push(top->child);
		}
	}

	tail->next = NULL;

	return start -> child;

}



/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* findMid(Node* head){      // have to find the first mid to handle even length list 
	Node* slow = head, *fast = head->next;
	while(slow and fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


// merge 2 sorted lists on their child pointers 
Node* mergeTwoSortedList(Node* head1, Node* head2){
	Node* start = new Node(-1);
	Node* tail = start;
	
	Node* t1 = head1, *t2= head2;
	while(t1 and t2){
		if(t1->data <= t2->data){
			tail->child = t1;
			tail = tail->child;
			t1 = t1->child;
		}
		else{
			tail->child = t2;
			tail = tail->child;
			t2 = t2->child;
		}
	}
	if(t1){
		tail->child = t1;
	}
	if(t2){
		tail->child = t2;
	}

	return start->child;		// NOTE: we are merging the list on child pointer
	
}

// Solution 2: Sequential merge O(N*K)
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL or head->next==NULL) return head;

	Node* right = flattenLinkedList(head->next);
	head->next = NULL;
	return mergeTwoSortedList(head, right);
}


// Solution 3: Used Divide and conquer, find mid, flattern left half, flatten right half and then merge left_flattened and right_flattened lists
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL or head->next==NULL) return head;

	Node* mid = findMid(head);		// we'll have to find the first mid(in case of even length list)
	Node* right = mid->next;		// otherwise we'll be stuck and eventually get runtime error
	mid->next = NULL;
	// cout<<mid->data<<endl;
	Node* left_flattened = flattenLinkedList(head);
	Node* right_flattened = flattenLinkedList(right);
	return mergeTwoSortedList(left_flattened, right_flattened);
	
}