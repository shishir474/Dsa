#include <bits/stdc++.h>
using namespace std;

class Animal{
    public:
    virtual void sound(){
        cout<<"Animal eats generic food"<<endl;
    }
};

class Cat : public Animal{
    public:
    void sound(){ // this print function is automatically a virtual function, since we have made it virtual in base class
        cout<<"cat eats cat food"<<endl;
    }
};

class Dog : public Animal{
    public:
    void sound(){ // this print function is automatically a virtual function, since we have made it virtual in base class
        cout<<"Dog eats dog food"<<endl;
    }
};

int main(){
    Animal* basePtr;
    Cat c1;
    Dog d1;
    basePtr = &d1;

    basePtr->sound();
    
    basePtr = &c1;
    basePtr->sound();

    // since basePtr is a base class pointer it should have called both the functions from the base class. but since the print function was declared virtual and the basePtr was referrring to myDerived class object-> hence it called print function of myDerived class
    
    // Advantage: Using the same base class pointer I can point to multiple derived class. Base class pointer jis bhi derived class ko point krra hoga uska function call hoga
}