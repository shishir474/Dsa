class Animal{  
    String color="white";  
}  

class Dog extends Animal{  
    String color="black";  
    void printColor(){  
        System.out.println(color);//prints color of Dog class  
        System.out.println(super.color);//prints color of Animal class  
    }  
}  

class TestSuper1{  
    public static void main(String args[]){  
    Dog d=new Dog();  
    d.printColor();  
}}  





// Second program of super keyword

class Animal{  
void eat(){System.out.println("eating...");}  
}  
class Dog extends Animal{  
void eat(){System.out.println("eating bread...");}  
void bark(){System.out.println("barking...");}  
void work(){  
super.eat();  
bark();  
}  
}  
class TestSuper2{  
public static void main(String args[]){  
Dog d=new Dog();  
d.work();  
}}  





// third program of super keyword

class Animal{  
Animal(){System.out.println("animal is created");}  
}  
class Dog extends Animal{  
Dog(){  
super();  
System.out.println("dog is created");  
}  
}  
class TestSuper3{  
public static void main(String args[]){  
Dog d=new Dog();  
}}  



// Real life example of super keyword

class Person{  
int id;  
String name;  
Person(int id,String name){  
this.id=id;  
this.name=name;  
}  
}  
class Emp extends Person{  
float salary;  
Emp(int id,String name,float salary){  
super(id,name);//reusing parent constructor  
this.salary=salary;  
}  
void display(){System.out.println(id+" "+name+" "+salary);}  
}  
class TestSuper5{  
public static void main(String[] args){  
Emp e1=new Emp(1,"ankit",45000f);  
e1.display();  
}}  