#include <bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real, imag;

    public:
    // constructor
    Complex(int r=0, int i=0){
        real = r;
        imag = i;
    }

    // overloading + operator
    Complex operator+(const Complex &c){
        Complex ans;
        ans.real = this->real + c.real;
        ans.imag = this->imag + c.imag;
        return ans;
    }

    void print(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

int main(){
  Complex c1(10,5), c2(20,5);
  Complex c3 = c1 + c2;
  c3.print();

}
