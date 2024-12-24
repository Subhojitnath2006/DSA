#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    if (n == 0) return false; // Check for empty matrix
    int m = mat[0].size();
    
    int low = 0;
    int high = n * m - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int midValue = mat[mid / m][mid % m]; // Map 1D index to 2D indices
        if (midValue == x) {
            return true;
        } else if (midValue > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int x;
    cin>>x;
    if(searchMatrix(arr,x)==true){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}