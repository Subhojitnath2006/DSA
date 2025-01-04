#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> anagrams(vector<string> &arr)
{
    // code here
    unordered_map<string, vector<string>> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        string temp = arr[i];
        sort(temp.begin(), temp.end());
        mpp[temp].push_back(arr[i]);
    }
    vector<vector<string>> ans;
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string>arr;
    for(int i=0;i<n;i++){
        
    }
}