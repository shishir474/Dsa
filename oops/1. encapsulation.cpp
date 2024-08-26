#include <bits/stdc++.h>
using namespace std;

class encapsulation{
    private:
    int x;

    public:
    void set(int val){
        x = val;
    }
    int get(){
        return x;
    }
};

int main(){
    encapsulation obj;
    obj.set(5);
    cout<<obj.get();
}
