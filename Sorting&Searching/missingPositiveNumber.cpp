#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int missingNumber = 1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == missingNumber) {
            missingNumber++;
        }
    }
    return missingNumber;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<missingNumber(arr);
}