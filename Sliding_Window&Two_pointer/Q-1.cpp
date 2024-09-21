//maximum points you can obtain from cards-->you can only pick cards from front or back not from middle and in a consecutive way
#include<iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Maximum cards you can pick: ";
    cin >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }

    int lSum = 0, rSum = 0, maxSum = 0;

    // Calculate the initial left sum (taking first 'k' cards)
    for(int i = 0; i < k; i++) {
        lSum += arr[i];
    }

    // Set maxSum to the initial left sum
    maxSum = lSum;

    // Now, iterate by removing elements from left and adding from right
    int rIndex = n - 1;
    for(int i = k - 1; i >= 0; i--) {
        lSum -= arr[i];        // Remove from left sum
        rSum += arr[rIndex];    // Add to right sum
        rIndex--;

        // Calculate the maximum sum
        maxSum = max(maxSum, lSum + rSum);
    }

    cout << "The maximum points you can obtain by picking " << k << " cards is: " << maxSum << endl;

    return 0;
}
