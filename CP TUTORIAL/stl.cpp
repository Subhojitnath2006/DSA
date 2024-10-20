//next permutation
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     while(next_permutation(arr, arr + n))
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// }

//queue
//swap function in queue
int main(){

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}