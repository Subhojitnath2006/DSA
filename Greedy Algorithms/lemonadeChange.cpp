#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    int cntFive = 0, cntTen = 0, cntTwenty = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
            cntFive++;
        else if (bills[i] == 10)
        {
            cntTen++;
            if (cntFive > 0)
                cntFive--;
            else
                return false;
        }
        else
        {
            cntTwenty++;
            if (cntTen > 0 && cntFive > 0)
            {
                cntTen--;
                cntFive--;
            }
            else if (cntFive >= 3)
            {
                cntFive -= 3;
            }
            else
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<int> bills(n);
    for (int i = 0; i < n; i++)
        cin >> bills[i];
    cout << lemonadeChange(bills);
    return 0;
}