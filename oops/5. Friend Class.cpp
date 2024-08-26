#include<iostream>
using namespace std;

class myClass1{
  friend class myClass2;
  
  int x;
  
  public:
  myClass1(){
      x=10;
  }
  int get(){
      return x;
  }
};

class myClass2{
    public: // passed cy referenece, then only change will be reflected. If passed by value, then x will remain 10 only
    void showData(myClass1 &obj){
        obj.x = 100;
    }
};

main()
{
    myClass1 m1;
    myClass2 m2;
    m2.showData(m1);
    cout<<m1.get();
}
