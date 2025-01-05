#include<bits/stdc++.h>
using namespace std;
int lcm(int a, int b) {
        return (1LL * a / __gcd(a, b)) * b; 
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            long long prod = nums[i];
            int Gcd = nums[i];
            int Lcm = nums[i];
            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                Gcd = __gcd(Gcd, nums[j]);
                Lcm = lcm(Lcm, nums[j]);
                if (prod == 1LL * Gcd * Lcm) { 
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
    int main(){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<maxLength(nums);
    }