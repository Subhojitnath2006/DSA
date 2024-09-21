#include<iostream>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Maximum Subarray length:";
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }
    int l=0,r=k-1;

    int sum=0;
    for(int i=l;i<=r;i++){
        sum=sum+arr[i];
    }
    int maxi=sum;
    while(r<n){
        sum=sum-arr[l];
        l++;
        r++;
        sum=sum+arr[r];
        maxi=max(maxi,sum);
    }
    cout<<"The maximun sum of consecutive "<<k<<" elements is:"<<maxi;
}