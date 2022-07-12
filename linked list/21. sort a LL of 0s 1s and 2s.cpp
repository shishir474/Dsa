// Single pass solution: By manipulating pointers
TC; O(n) and SC: O(1);

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zerod = new Node(-1);
        Node* oned = new Node(-1);
        Node* twod = new Node(-1);
        Node* zero=zerod;
        Node* one = oned;
        Node* two = twod;
        
        Node* t=head;
        while(t){
            if(t->data==0){
                zero->next = t;
                zero=zero->next;
            }
            else if(t->data==1){
                one->next=t;
                one=one->next;
            }
            else{
                two->next=t;
                two=two->next;
            }
            t=t->next;
        }
        
        zero->next=(oned->next) ? oned->next : twod->next;
        one->next = twod->next;
        two->next = NULL;
        
        Node* ans=zerod->next;
        delete zerod;
        delete oned;
        delete twod;
        
        return ans;
        
    }
};

// solution2:
traverse once and determine the count of zeroes,ones and twos
Then traverse again and place first k1 pos with 0's then next k2 pos with 1's and the rest positions with 2's
TC: O(n)+O(n) = O(n);
sc; O(1);