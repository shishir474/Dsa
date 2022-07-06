// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int getLength(struct Node* head){
    struct Node* t=head;
    int len=0;
    while(t){
        len++;
        t=t->next;
    }
    return len;
}

struct Node* getTail(struct Node* head){
    struct Node* t=head;
    while(t->next != NULL) t=t->next;
    return t;
}

int countTriplets(struct Node* head, int x)
{
        int ans=0,len=getLength(head);
        struct Node* tail = getTail(head);
        struct Node* t=head;
        for(int c=1;c<=len-2;c++,t=t->next){
            struct Node* l=t->next, *r=tail;
            while(l!=r){
                if(l->data + r->data == x-t->data){
                    ans++;
                    l=l->next;
                    r=r->prev;
                }
                else if(l->data + r->data < x-t->data){
                    l=l->next;
                }
                else{
                    r=r->prev;
                }
            }
        }


        return ans;
    
}
