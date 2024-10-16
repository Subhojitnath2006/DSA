#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int noOfChocolate(int arr[], int n, int time)
{
    priority_queue<int> p;
    for (int i = 0; i < n; i++)
        p.push(arr[i]);

    int ans = 0;
    while (time > 0)
    {
        int chocolate = p.top();
        p.pop();
        ans += chocolate;
        p.push(chocolate / 2);
        time--;
    }

    return ans;
}

// leetcode qustion-->1046(Last stone weight)
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> p;

    for (int i = 0; i < stones.size(); i++)
        p.push(stones[i]);
    // y is heaviest and x is second heaviest
    while (p.size() > 1)
    {

        int y = p.top();
        p.pop();
        int x = p.top();
        p.pop();

        if (x != y)
            p.push(y - x);
    }
    if (!p.empty())
        return p.top();
    else
        return 0;
}

// Leetcode: 1962--> Remove stones to minimize total
int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> p;

    for (int i = 0; i < piles.size(); i++)
    {
        p.push(piles[i]);
    }

    while (k > 0)
    {
        int stone = p.top() - floor(p.top() / 2);
        p.pop();
        p.push(stone);
        k--;
    }

    int ans = 0;

    while (!p.empty())
    {
        ans += p.top();
        p.pop();
    }
    return ans;
}
// Leetcode: 2208-->Minimum operations to halve array Sum
int halveArray(vector<int> &nums)
{
    double initialSum = 0;
    priority_queue<double> p;
    for (int i = 0; i < nums.size(); i++)
    {
        initialSum += nums[i];
        p.push(nums[i]);
    }

    double reducedSum = initialSum;
    int count = 0;

    while (reducedSum > initialSum / 2)
    {
        double num = p.top();
        p.pop();
        reducedSum -= num / 2;
        p.push(num / 2);
        count++;
    }
    return count;
}

// profit maximization-->InterviewBit
int maxProfit(vector<int> &A, int B)
{

    priority_queue<int> p;

    for (int i = 0; i < A.size(); i++)
        p.push(A[i]);
    int profit = 0;

    while (B > 0 && !p.empty())
    {
        int price = p.top();
        p.pop();
        profit += price;
        p.push(price - 1);
        B--;
    }
    return profit;
}

// Kth smallest element in an array using priority Queue
// Expected Time Complexity: O(n+(max_element) )
// Expected Auxiliary Space: O(max_element)
int kthSmallest(vector<int> &arr, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < arr.size(); i++)
        p.push(arr[i]);
    int kSmallest;
    while (k > 0)
    {
        kSmallest = p.top();
        p.pop();
        k--;
    }
    return kSmallest;
}
// Kth largest element in an array using priority Queue

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> p;

    for (int i = 0; i < nums.size(); i++)
        p.push(nums[i]);
    int kLargest;
    while (k > 0)
    {
        kLargest = p.top();
        p.pop();
        k--;
    }
    return kLargest;
}

// kth largest element in a stream
// for example-->
/*Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so answer will be -1.
For 2, the 4th largest element doesn't
exist so answer will be -1.
For 3, the 4th largest element doesn't
exist so answer will be -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.*/

vector<int> kthLargest(int k, int arr[], int n)
{
    // code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < k - 1; i++)
    {
        ans.push_back(-1);
        p.push(arr[i]);
    }
    p.push(arr[k - 1]);
    for (int i = k; i <= n; i++)
    {
        ans.push_back(p.top());
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return ans;
}

// check if a binary is heap or not
// int count(struct Node* root){
//       if(root==NULL) return 0;
      
//       return 1+count(root->left)+count(root->right);
//   }
  
//   bool CBT(struct Node* root,int index,int total_nodes){
//       if(root==NULL) return 1;
//       if(index>=total_nodes) return 0;
      
//       return CBT(root->left,2*index+1,total_nodes)&&CBT(root->right,2*index+2,total_nodes);
//   }
//   bool MaxHeap(struct Node* root){
//       if(root->left){
//           if(root->data < root->left->data) return 0;
//           if(!MaxHeap(root->left)) return 0;
//       }
//       if(root->right){
//           if(root->data < root->right->data) return 0;
//           return MaxHeap(root->right);
//       }
//       return 1;
//   }
//     bool isHeap(struct Node* tree) {
//         // code here
//         int num=count(tree);
//         if(!CBT(tree,0,num)) return 0;
//         return MaxHeap(tree);
        
//     }

//find kth element of a matrix using priority queue
//Time complexity-->o(n)+o(klog(n))
#define MAX 1000
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  vector<pair<int,pair<int,int>>>temp;
  
  for(int i=0;i<n;i++){
      temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
  }
  
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
  
  int ans;
  pair<int,pair<int,int>>Element;
  
  int i,j;
  
  while(k--){
      Element=p.top();
      p.pop();
      ans=Element.first;
      i=Element.second.first;
      j=Element.second.second;
      
      if(j+1<n){
          p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
      }
  }
  return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int time;
    cin >> time;
    cout << noOfChocolate(arr, n, time);

    int size;
    cin >> size;
    vector<int> stones;
    for (int i = 0; i < size; i++)
    {
        cin >> stones[i];
    }
    cout << lastStoneWeight(stones);
    return 0;
}