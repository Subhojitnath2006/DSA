//maximum number of consecutive ones atmost by flipping k zeros
//we can convert this question into --> longest subarray with atmost k zeros
#include<iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Maximum no of zeros to be flipped: ";
    cin >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }
    int l=0,r=0,maxLen=0,zeros=0;
    while(r<n){
        if(arr[r]==0) zeros++;
        if(zeros>k){
            if(arr[l]==0) zeros--;
            l++;
        }
        if(zeros<=k){
            maxLen=max(maxLen,r-l+1);

        }
        r++;
    }
    cout<<"Maximum number of consecutive ones atmost by flipping "<<k<<" zeros is: "<<maxLen;
    }