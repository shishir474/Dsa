#include <bits/stdc++.h>
using namespace std;

class Base{
    public:
    void print(){
        cout<<"Base function called"<<endl;
    }
};

class Derived: public Base{
    public:
    void print(){
       Base::print(); // accessing the overriden function
       cout<<"Derived function called"<<endl;
    }
};

int main(){
    Derived d1;
    d1.print();
    
    // This is how we access the overriden function from main using scope resolution operator
    d1.Base::print();
    
    // ANother approach is of crating pointer of base and making it point to object of Derived
    Base* ptr= &d1;
    ptr->print();
    
    
    // had we called print() from object of base class there would have no overriding
    Base b;
    b.print();

}




