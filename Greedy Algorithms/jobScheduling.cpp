#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id, deadline, profit;
};
static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs, jobs + n, comp);
        
        int totProfit = 0, cnt = 0, maxDeadline = -1;
        
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }
        
        int hash[maxDeadline + 1];
        fill(hash, hash + maxDeadline + 1, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = jobs[i].deadline; j > 0; j--) {
                if(hash[j] == -1) {
                    totProfit += jobs[i].profit;
                    cnt++;
                    hash[j] = jobs[i].deadline;
                    break;
                }
            }
        }
        
        return {cnt, totProfit};
    }
    int main(){
        int n;
        cin >> n;
        Job arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
        }
        vector<int> ans = JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1];
    }