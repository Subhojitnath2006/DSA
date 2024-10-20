#include<iostream>
using namespace std;
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        int li,ri;
        cin>>li>>ri;
        arr[li]++;
        arr[ri+1]--;
    
    }
    // calculate prefix sum
    int p[n]={0};
    p[0]=arr[0];
    for(int i=1;i<n;i++){
        p[i]=p[i-1]+arr[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<p[r]-p[l-1]<<endl;
    }  
}