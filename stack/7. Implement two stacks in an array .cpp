Implement two stacks in an array 

class twoStacks{
    int* arr;
    int size;
    int top1,top2;
    public:
    twoStacks(int n){
        size = n;
        arr = new int[n];
        top1=-1;
        top2=n;
    }

    void push1(int x){
        if (top2-top1 == 1) return;
        top1++;
        arr[top1] = x;
    }

    void push2(int x){
        if (top2-top1 == 1) return;
        top2--;
        arr[top2] = x;
    }

    int pop1(){
        if(top1==-1) return -1;
        
        int ans=  arr[top1];
        top1--;
        return ans;
    }

     int pop2(){
        if(top2==size) return -1;
        int ans =  arr[top2];
        top2++;
        return ans;
    }
};

int main(){
    twoStacks ts(5);
    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);
    ts.push2(5);
    ts.pop1();

}