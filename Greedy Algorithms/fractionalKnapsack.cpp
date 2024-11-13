#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int weight;
};

static bool comp(item val1, item val2)
{
    double ratio1 = (double)val1.value / val1.weight;
    double ratio2 = (double)val2.value / val2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<item> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].value = val[i];
        arr[i].weight = wt[i];
    }

    sort(arr.begin(), arr.end(), comp);

    double totValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= capacity)
        {
            totValue += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {
            totValue += (double)arr[i].value * capacity / arr[i].weight;
            break;
        }
    }
    return totValue;
}
int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int capacity;
    cin >> capacity;
    cout << fractionalKnapsack(val, wt, capacity);
}