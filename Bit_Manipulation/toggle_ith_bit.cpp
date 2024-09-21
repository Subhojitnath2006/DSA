#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"Enter the ith bit to toggle:";
    cin>>i;
    cout<<"The number after toggleing the "<<i<<"th bit is: "<<n<<endl;
    int ans=0;
    //using right shift
    if(((n>>i)&1)!=0) { //ith bit is 1->then convert it to 0
        ans=n&(~(1<<i));
    }
    else { //ith bit is zero->then convert it to 1
        ans=((1<<i)|n);
    }

    cout<<"The number after toggleing the "<<i<<"th bit is: "<<ans;
}