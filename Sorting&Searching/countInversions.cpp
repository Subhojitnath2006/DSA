#include<bits/stdc++.h>
using namespace std;
int cnt; // Global variable to count inversions
    
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                // Increment inversion count for all remaining elements in the left subarray
                cnt += (mid - left + 1);
                right++;
            }
        }
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
    
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);      // Corrected from mid-1
        mergeSort(arr, mid + 1, high); // Corrected from mid+1
        merge(arr, low, mid, high);
    }
    
    int inversionCount(vector<int>& arr) {
        cnt = 0; // Initialize inversion count
        mergeSort(arr, 0, arr.size() - 1);
        return cnt;
    }
    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<inversionCount(arr);
    }