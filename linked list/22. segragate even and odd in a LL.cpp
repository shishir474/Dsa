Segregate even and odd nodes in a Link List 

Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

NOTE: Dont create a new linked list, instead rearrange the provided one.


Example 1:

Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers 
so they appear first and 17,15,9 are odd 
numbers that appear later.


class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evend = new Node(-1);
        Node* oddd = new Node(-1);
        Node* even=evend;
        Node* odd=oddd;
        Node* t=head;
        while(t){
            if(t->data&1){
                odd->next=t;
                odd=odd->next;
            }
            else{
                even->next=t;
                even=even->next;
            }
            t=t->next;
        }
        
        even->next = oddd->next;
        odd->next=NULL;         // IMPORTANT
        Node* ans = evend->next;
        delete evend;
        delete oddd;
        return ans;
        
        
    }
};