#include <bits/stdc++.h>
using namespace std;
int myAtoi(char *s)
{
    // Skip leading whitespaces
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }

    // Handle optional sign
    int sign = 1;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    // Convert digits to integer
    int ans = 0;
    while (s[i] && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        // Check for overflow
        if (ans > (INT_MAX - digit) / 10)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        i++;
    }

    return ans * sign;
}
int main()
{
    char s[100];
    cin >> s;
    cout << myAtoi(s);
}