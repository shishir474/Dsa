// CPP program to illustrate
// use of new keyword
#include<iostream>
using namespace std;
class car
{
	string name;
	int num;

	public:
	    car(){
	        name="";
	        num=0;
	    }
		car(string a, int n)
		{
			cout << "Constructor called" << endl;
			this ->name = a;
			this ->num = n;
		}

		void enter()
		{
			cin>>name;
			cin>>num;
		}

		void display()
		{
			cout << "Name: " << name << endl;
			cout << "Num: " << num << endl;
		}
};

int main()
{
	// Using new keyword
	car *p = new car("Honda", 2017);
    car *c = new car;
	p->display();
	c->display();
}
