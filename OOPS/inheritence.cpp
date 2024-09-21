#include<iostream>
using namespace std;

class Human{ //base class/parent class
    protected:
    string name;
    int age;
    public:
    void work(){
        cout<<"i am working"<<endl;
    }
    Human(string name,int age){
        this->name=name;
        this->age=age;
    }
    // Human(){cout<<"Hello Human"<<endl;}
    // ~Human(){cout<<"Hello Human Destructor"<<endl;}
};
class student:public Human{ //child class/derived class
    int roll_number,fees;

    public:
    student(string name,int age,int roll,int fees):Human(name,age){
        
        this->roll_number=roll;
        this->fees=fees;
    }
    void display(){
        cout<<name<<" "<<age<<" "<<roll_number<<" "<<fees<<endl;
    }
    // student(){cout<<"Hello constructor"<<endl;}
    // ~student(){cout<<"Hello Destructor"<<endl;}
};
int main(){

    student A1("Rohit",26,32,99);
    A1.work();
    A1.display();
    // student A2;
    return 0;
}
//constructor of parent class called first then the child class
