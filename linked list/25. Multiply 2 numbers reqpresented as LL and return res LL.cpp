2
7 5 9 4 6 -1
0 -1
0 2 3 4 0 - 1
0 0 1 -1

int length(Node* head){
    Node* t=head;
    int c=0;
    while(t){
        c++; t=t->next;
    }
    return c;
}

Node* reverse(Node* head){
    Node* t=head,*prev=NULL;
    while(t){
        Node* next=t->next;
        t->next=prev;
        prev=t;
        t=next;
    }
    return prev;
}

Node* make_list(int length){
    Node* st=new Node(-1);
    Node* tail=st;
    while(length--){
        Node* nn = new Node(0);
        tail->next=nn;
        tail=nn;
    }
    return st->next;
}

Node *multiplyLL(Node *head1, Node *head2)
{
    int m=length(head1), n=length(head2);
    Node* firstHead=reverse(head1), *secondHead=reverse(head2);
    Node* res=make_list(m+n);
    Node* t2=secondHead;
    Node* resstart=res;
    while(t2){
        Node* t1=firstHead;
        int carry=0;
        Node* resptr=resstart;
        while(t1){
            int p=t1->data*t2->data + carry;
            resptr->data+=p%10;
            carry=p/10 + resptr->data/10;  //[important]
            resptr->data%=10;              // [important]
            resptr=resptr->next;
            t1=t1->next;
        }
        if (carry > 0){
            resptr->data+=carry;
        }
        resstart=resstart->next;
        t2=t2->next;
    }
    
    Node* fh= reverse(res);
    while(fh->data==0 and fh->next){
        fh=fh->next;
    }
    return fh;
    
}

