class Solution
{
    public:
    Node* reverse(Node* head){
        Node* t=head;
        Node* prev=NULL;
        while(t){
            Node* next=t->next;
            t->next=  prev;
            prev=t;
            t=next;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        Node* resd=new Node(-1);
        Node* res = resd;
        Node* t=reverse(head);
        int mx=INT_MIN;
        while(t){
            if(t->data >= mx){  // delete values strictly gretaer hence used >=
                res->next = t;
                res=t;
                mx=t->data;
            }
            t=t->next;
        }
        
        res->next=NULL;  // IMPORTANT
        
        return reverse(resd->next);
        
        
    }
    
};