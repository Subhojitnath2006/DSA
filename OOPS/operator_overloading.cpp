#include<iostream>
using namespace std;
class Complex{
    int real,img;
    public:
    Complex(){}
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    Complex operator+(Complex &A){ //operator overloading
        Complex B;
        B.real=real+A.real;
        B.img=img+A.img;
        return B;
    }
    void display(){
        cout<<"The sum is:"<<real<<"+i"<<img<<endl;
    }
};

int main(){
    Complex C1(2,3);
    Complex C2(4,5);
    Complex C3=C1+C2; //c1.operator+(c2)
    C3.display();
}
/*
In C++, most operators can be overloaded, but there are a few exceptions. The operators that cannot be overloaded are:

Scope Resolution Operator (::)
Member Access or Dot Operator (.)
Pointer-to-member Operator (.*)
Ternary or Conditional Operator (?:)
Sizeof Operator (sizeof)
Typeid Operator (typeid)
Casting Operators (static_cast, dynamic_cast, const_cast, reinterpret_cast)
*/