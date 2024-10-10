#include<iostream>
using namespace std;
class MaxHeap{
    int *arr;
    int size; //total element in heap;
    int total_size;//total capacity of heap;
    public:
    MaxHeap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }
    void insert(int value){
        //if heap size is available or not
        if(size==total_size){
            cout<<"Overflow detected"<<endl;
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        //compare with its parent

        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        cout<<arr[index]<<" is inserted into heap"<<endl;
    }

    void print(){
        cout<<"The heap elements are: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //delete a node
    void Delete(){
        if(size==0){
            cout<<"Underflow detected"<<endl;
            return;
        }
        arr[0]=arr[size-1];
        size--;
        int index=0;
        int left=2*index+1;
        int right=2*index+2;
        while(left<size && arr[index]<arr[left]){
            swap(arr[index],arr[left]);
            index=left;
            left=2*index+1;
            right=2*index+2;
        }
        while(right<size && arr[index]<arr[right]){
            swap(arr[index],arr[right]);
            index=right;
            left=2*index+1;
            right=2*index+2;
        }
        cout<<arr[index]<<" is deleted from heap"<<endl;
    }
};
int main(){
    MaxHeap h(10);
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(5);
    h.insert(35);
    h.insert(40);
    h.print();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.print();
    return 0;
}