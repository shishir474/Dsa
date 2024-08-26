#include <bits/stdc++.h>
using namespace std;

class functionOverLoading{
    public:
    // function with one integer paramenter
    void func(int val){
        cout<<val<<endl;
    }

    // function with same name but with one duoble parameter
     void func(double val){
        cout<<val<<endl;
    }

    // function with the same name but with 2 integer parameters
    void func(int val1, int val2){
        cout<<val1<<" "<<val2<<endl;
    }
};

int main(){
    functionOverLoading obj;
    func(5);
    func(5.5);
    func(5,10);
}
