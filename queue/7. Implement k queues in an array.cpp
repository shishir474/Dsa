 7. Implement k queues in an array

class kQueue{
    public:
    int n,k;
    int* front;
    int* rear;
    int* arr; 
    int* next;
    int freespot;
    kQueue(int size, int noOfQueues){
        n=size;
        k=noOfQueues;
        freespot=0;
        front= new int[k];
        rear = new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        arr = new int[n];
        next = new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
    }

// push x in mth queue
    void push(int x, int m){
        // overflow check
        if(freespot == -1){
            cout<<"queue is full";
            return;
        }
        
        // find index
        int index = freespot;
        
        // update freespot
        freespot = next[index];

        // check whether first element
        if(front[m-1]==-1){
            front[m-1]=index;
        }
        else{
            // link new element with prev element
            next[rear[m-1]] = index;
        }

        // update next
        next[index]=-1;

        // update rear
        rear[m-1]=index;

        // push element
        arr[index] = x;
    }

    int pop(int m){
        // check underflow
        if(front[m-1]==-1){
            cout<<"underflow"<<endl;
            return -1;
        }
        // determine index
        int index = front[m-1];

        // update front
        front[m-1]=next[index];

        // update next
        next[index] = freespot;

        // index becomes freespot
        freespot = index;

        return arr[index];
    }
};

int main(){
    kQueue q(10,3);
    q.push(10,1);
    q.push(15,1);
    q.push(20,2);
    q.push(25,1);

    cout<<q.pop(1)<<" "<<q.pop(1)<<" "<<q.pop(2)<<" "<<q.pop(1)<<endl;


}
