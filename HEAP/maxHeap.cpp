//create a max heap in O(n) time complexity
#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n){
    //step down
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
}

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n];
    cout<<"Enter heap elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildMaxHeap(arr, n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}