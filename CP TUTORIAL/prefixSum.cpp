#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;i++)
    prefix[i]=a[i]+prefix[i-1];
    int t;
    cout<<"Enter no of queries : ";
    cin>>t;
    while(t--){
        int l,r;
        cout<<"Enter range : ";
        cin>>l>>r;
        cout<<"Sum of range : ";
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
    return 0;
}