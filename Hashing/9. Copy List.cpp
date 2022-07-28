A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.


/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* fh=new RandomListNode(-1), *st = fh, *temp = A;
    map<RandomListNode*, RandomListNode*> mp; // original list NOde-> Cloned List NOde
    while(temp){
        RandomListNode* newNode = new RandomListNode(temp->label);
        mp[temp] = newNode;
        st->next = newNode;
        st = st->next;
        temp = temp->next;
    }

    RandomListNode* t1 = A;
    while(t1){
        if (t1->random){
            mp[t1]->random = mp[t1->random];
        }
        else{
            mp[t1]->random = NULL;
        }
        t1 = t1->next;
    }

    return fh->next;
}
