#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"Enter the no of bit to check:";
    cin>>i;

    //using right shift
    if(((n>>i)&1)!=0) cout<<i<<"th bit is set";
    else cout<<i<<"th bit is not set";

    //using left shift
    if(((1>>i)&n)!=0) cout<<i<<"th bit is set";
    else cout<<i<<"th bit is not set";
}