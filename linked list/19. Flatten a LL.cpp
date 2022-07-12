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








solution 2:

Node* merge(Node* root1, Node* root2){
    if(!root1) return root2;
    else if(!root2) return root1;
    Node* res;
    if(root1->data < root2->data){
        res = root1;
        res->bottom= merge(root1->bottom, root2);
    }
    else{
        res =  root2;
        res->bottom = merge(root1,root2->bottom);
    }
    res->next=NULL;
    return res;
}
Node *flatten(Node *root)
{
    if(!root || root->next==NULL) return root;
    root->next = flatten(root->next);
    Node* res = merge(root,root->next);
    return res;
}

Time Complexity: O(N*N*M) - where N is the no of nodes in main linked list (reachable using right pointer) and M is the no of node in a single sub linked list (reachable using down pointer). 




Explanation: As we are merging 2 lists at a time,


After adding first 2 lists, time taken will be O(M+M) = O(2M).
Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
Then we will merge another list -> time = O(3M + M).
We will keep merging lists to previously merged lists until all lists are merged.
Total time taken will be O(2M + 3M + 4M + .... N*M) = (2 + 3 + 4 + ... + N)*M
Using arithmetic sum formula: time = O((N*N + N - 2)*M/2)
Above expression is roughly equal to O(N*N*M) for large value of N

Space Complexity: O(N*M) - because of the recursion. The recursive functions will use recursive stack of size equivalent to total number of elements in the lists, which is N*M.

