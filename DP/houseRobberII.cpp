#include<bits/stdc++.h>
using namespace std;

int rob1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) {
            pick += prev2;
        }
        int notPick = prev;
        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0]; 
    if (n == 0) return 0;

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(nums[i]);
        if (i != n - 1) temp2.push_back(nums[i]);
    }
    return max(rob1(temp1), rob1(temp2));
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<rob(nums);
}