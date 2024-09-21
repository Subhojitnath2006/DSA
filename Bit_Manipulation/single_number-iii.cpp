#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }

    int Xorr=0;
    for(int i=0;i<n;i++){
        Xorr=Xorr^arr[i];
    }
    int rightMost=(Xorr&(Xorr-1))^Xorr;
    int b1,b2=0;
    for(int i=0;i<n;i++){
        if((rightMost&arr[i])) b1=b1^arr[i];
        else b2=b2^arr[i];
    }
    cout<<"The numbers which appears one in the array are:"<<b1<<" "<<b2;
}