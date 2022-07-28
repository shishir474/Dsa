 Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.


TC: O(n2log(k)) -> while loop will run n2 times and log k operation for pq
sc; O(k)   

 struct compare{
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<Node*, vector<Node*>, compare> pq;
           for(int i=0;i<K;i++){
               pq.push(arr[i]);
           }
           
           Node* dummy = new Node(-1);
           Node* tail = dummy;
           
           while(!pq.empty()){
               Node* t=pq.top();
               pq.pop();
               tail->next = t;
               tail=t;
               if(t->next){
                   pq.push(t->next);
               }
           }
           tail->next=NULL;
           return dummy->next;
    }