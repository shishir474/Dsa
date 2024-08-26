// Interfaces & abstract class-> virtual functions those functions which does not contain theri implementation,only their declaration part is provided inside the class
// so all the classes which are inheriting these abstract class should provide implementation for these virtual function. IN fact they should override these virtual functions

#include <bits/stdc++.h>
using namespace std;

class Shape{
    protected:
    int height, width;

    public:
    virtual int getArea() = 0;
    void setHeight(int h){
        height = h;
    }
    void setWidth(int w){
        width = w;
    }
};

class Rectangle : public Shape{
    public:
    int getArea(){
        return height*width;
    }
};

class Triangle : public Shape{
    public:
    int getArea(){
        return (height*width)/2;
    }
};

int main(){
    Rectangle r;
    r.setHeight(7);
    r.setWidth(5);
    cout<<r.getArea()<<endl;

    Triangle t;
    t.setHeight(10);
    t.setWidth(5);
    cout<<t.getArea()<<endl;

}