#include<iostream>
using namespace std;
void prefixSum(int a[],int n){
    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;i++)
    prefix[i]=a[i]+prefix[i-1];
    cout<<"Final array : ";
    for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
}
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    int t;
    cout<<"Enter no of queries : ";
    cin>>t;
    while(t--)
    {
        int l,r,x;
        cout<<"Enter range : ";
        cin>>l>>r;
        cout<<"Enter value : ";
        cin>>x;
        a[l]+=x;
        if(r+1<n)
        {
            a[r+1]-=x;
        }
    }
    prefixSum(a,n);
    return 0;
}