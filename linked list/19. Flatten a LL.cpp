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

struct compare{
    bool operator()(Node* a, Node* b){
        return a->data>b->data;
    }
};

Node* mergeKsortedLL(vector<Node *> &v){
    int k = v.size();
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i=0;i<k;i++){
        pq.push(v[i]);
    }
    struct Node* st=new Node(-1); // dummy node;
    struct Node* tail = st;

    while(!pq.empty()){
        struct Node* top = pq.top();
        pq.pop();
        tail->bottom = top;
        tail = tail->bottom;
        if(top->bottom) pq.push(top->bottom);
    }

  return st->bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   vector<Node* > v;
   Node* temp =  root;
   while(temp!=NULL){
       v.push_back(temp);
       temp = temp->next;
   }
   // IMPORTANT STEP
   for (int i=0;i<v.size();i++){
       v[i]->next=NULL;
   }
   
   return mergeKsortedLL(v);
}
