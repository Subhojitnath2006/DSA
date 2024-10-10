//create a max heap in O(n) time complexity
#include<iostream>
using namespace std;

/*Steps:
1. Build max heap
2. Delete root node and heapify the remaining nodes
3. Repeat step 1 and 2
4. Repeat step 3 until heap is empty
5. return root node
Time complexity: O(nlogn)
Space complexity: O(1)*/
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

void heapSort(int arr[], int n){
    // for(int i=0;i<n-1;i++){
    //     swap(arr[0], arr[n-1-i]);
    //     heapify(arr, n-1-i, 0);
    // }
    while(n>0){
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr, n, 0);
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
    int size=n;

    heapSort(arr,n);

    cout<<"Sorted array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}