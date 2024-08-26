#include <bits/stdc++.h>
using namespace std;

class myBase{
    public:
    void show(){
        cout<<"myBase show function called"<<endl;
    }
    virtual void print(){
        cout<<"myBase print function called"<<endl;
    }
};

class myDerived : public myBase{
    public:
    void show(){
        cout<<"myDerived show function called"<<endl;
    }
    void print(){ // this print function is automatically a virtual function, since we have made it virtual in base class
        cout<<"myDerived print function called"<<endl;
    }
};

int main(){
    myBase* basePtr;
    myDerived d1;
    basePtr = &d1;



    basePtr->print();
    basePtr->show();

    // since basePtr is a base class pointer it should have called both the functions from the base class. but since the print function was declared virtual and the basePtr was referrring to myDerived class object-> hence it called print function of myDerived class
    
    // Advantage: Using the same base class pointer I can point to multiple derived class. Base cla ss pointer jis bhi derived class ko point krra hoga uska function call hoga
}