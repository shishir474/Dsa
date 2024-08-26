#include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
    void getArea(){
        cout<<"Shape Area"<<endl;
    }
};

class Square: public Shape{
    private:
    int length;

    public:
    // constructor
    Square(int l){
     length = l;
    }
    void getArea(){
        Shape::getArea();
        cout<<length*length<<endl;
    }
};

class Triangle: public Shape{
    private:
    int base,height;

    public:
    // constructor
    Triangle(int b, int h){
     base = b;
     height = h;
    }
    void getArea(){
        cout<<(base*height)/2<<endl;
    }
};

int main(){
  Shape obj;
  obj.getArea();
  cout<<endl;

  Square s(5);
  s.getArea();
  cout<<endl;

  Triangle t(6,3);
  t.getArea();

}




