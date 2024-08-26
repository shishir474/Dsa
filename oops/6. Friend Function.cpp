#include<iostream>
using namespace std;

class Distance{
  int meters;

  public:
  Distance(){
      meters = 0;
  }
  void displayData(){
      cout<<"meters "<<meters<<endl;
  }
  
  friend void addValue(Distance &d);
};

// need to be passed by reference then only changes will reflect
void addValue(Distance &d){
    d.meters = d.meters + 5;
}


main()
{
    Distance d1;  // meters=0;
    d1.displayData(); // 0

    // friend function call. add value is an independent function,It doesnot require an object to call
    addValue(d1); // passed by reference

    d1.displayData(); // 5
}
