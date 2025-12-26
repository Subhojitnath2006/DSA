#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int arr[],int seg[],int Or){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind + 1,low,mid,arr,seg,!Or);
    build(2 * ind + 2,mid+1,high,arr,seg,!Or);
    if(Or){
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
}
void update(int ind,int low,int high,int i,int val,int seg[],int Or){
    if(low == high){
        seg[ind] = val;
        return;
    }
    int mid = (low + high)/2;
    if(i <= mid) update(2*ind + 1,low,mid,i,val,seg,!Or);
    else update(2*ind + 2,mid+1,high,i,val,seg,!Or);
    if(Or){
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    int el = pow(2,n);
    int arr[el];
    for(int i=0;i<el;i++){
        cin>>arr[i];
    }
    int seg[4*n];
    if(n % 2 == 0) build(0,0,el-1,arr,seg,0);
    else build(0,0,el-1,arr,seg,1);
    while(q--){
        int p,b;
        cin>>p>>b;
        p--;
        if(n % 2 == 0) update(0,0,el-1,p,b,seg,0);
        else update(0,0,el-1,p,b,seg,1);
        cout<<seg[0]<<endl;
    }
}
int main(){
    solve();
}