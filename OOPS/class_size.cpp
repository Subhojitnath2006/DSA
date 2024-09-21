#include<iostream>
using namespace std;
class A{
    char a;
    int b;
    char c;
};
class B{
    char a;
    char c;
    int b;
    
};
class C{ //empty class
    
};
int main(){
    A obj1;
    cout<<sizeof(obj1)<<endl;
    B obj2;
    cout<<sizeof(obj2)<<endl;
    C obj3;
    cout<<sizeof(obj3)<<endl;
}