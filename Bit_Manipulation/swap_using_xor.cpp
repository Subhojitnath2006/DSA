#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two number: ";
    cin>>a>>b;

    cout<<"Before Swapping: a ="<<a<<" b = "<<b<<endl;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"After Swapping: a ="<<a<<" b = "<<b<<endl;
}