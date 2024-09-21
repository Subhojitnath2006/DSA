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

    int Xor=0;
    for(int i=0;i<n;i++){
        Xor=Xor^arr[i];
    }
    cout<<"The number which present once in the array :"<<Xor;
}