#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"Enter the no of bit to check:";
    cin>>i;

    cout<<"Number before setting the "<<i<<"th bit is: "<<n<<endl;
    n=((1<<i)|n);
    cout<<"Number after setting the "<<i<<"th bit is: "<<n;
}