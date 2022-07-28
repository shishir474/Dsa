Problem Description

Given a linked list A , reverse the order of all nodes at even positions.



Problem Constraints
1 <= Size of linked list <= 100000



Input Format
First and only argument is the head of the Linked-List A.



Output Format
Return the head of the new linked list.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev=  curr;
        curr=next;
    }
    return prev;
}

ListNode* merge(ListNode* oddHead, ListNode* evenHead){
    ListNode* head = new ListNode(0);
    ListNode* start = head;
    ListNode* t1 = oddHead, *t2 = evenHead;
    int c=0;
    while(t1!=NULL || t2!=NULL){
        c++;
        if (c%2 == 1){
            start->next = t1;
            t1 = t1->next;
        }
        else{
            start->next = t2;
            t2 = t2->next;
        }
        start = start->next;
    }

    start->next = NULL;  // IMPORTANT
    return head->next;
}
ListNode* Solution::solve(ListNode* A) {
// Solution 1: O(n) space

    // if (A==NULL || A->next==NULL) return A;
    // ListNode* temp = A;
    // vector<int> v;
    // int c=0;
    // while(temp){
    //     c++;
    //     if (c%2==0) v.push_back(temp->val);
    //     temp = temp->next;
    // }

    // int ind=v.size()-1;
    // temp=A;
    // c=0;
    // while(temp){
    //     c++;
    //     if (c%2==0) temp->val = v[ind--];
    //     temp = temp->next;
    // }
    // return A;






// Solution 2: Constant space:
    ListNode* oddHead = new ListNode(0);
    ListNode* evenHead = new ListNode(0);
    ListNode* o1 = oddHead, *e1 = evenHead;
    ListNode* temp = A;
    int c=0;
    while(temp){
        c++;
        if (c%2 == 1){
            o1->next = temp;
            o1 = o1->next;
        }
        else{
            e1->next = temp;
            e1 = e1->next;
        }
        temp = temp->next;
    }

    o1->next=NULL; // IMPORTANT
    e1->next=NULL; // IMPORTANT
    return merge(oddHead->next, reverse(evenHead->next));











}
