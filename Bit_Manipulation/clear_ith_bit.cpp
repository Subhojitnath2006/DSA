#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"Enter the no of bit to check:";
    cin>>i;

    cout<<"Number before claering the "<<i<<"th bit is: "<<n<<endl;
    n=n&(~(1<<i));
    cout<<"Number after clearing the "<<i<<"th bit is: "<<n;
}