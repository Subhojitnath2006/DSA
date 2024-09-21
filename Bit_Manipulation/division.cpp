#include <iostream>
#include <cmath> // Include for abs and INT32_MAX
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (divisor == 0) return INT32_MAX; // Handle division by zero

    bool sign = (dividend < 0) ^ (divisor < 0); // Determine the sign of the result
    int n = abs(dividend);
    int d = abs(divisor);
    int ans = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) cnt++;
        ans += (1 << cnt);
        n -= (d << cnt);
    }

    if (ans >= (1 << 31)) return sign ? INT32_MIN : INT32_MAX; // Handle overflow

    return sign ? -ans : ans;
}

int main() {
    int dividend, divisor;
    cout << "Enter the dividend and divisor: ";
    cin >> dividend >> divisor;

    cout << "The division is: " << divide(dividend, divisor) << endl;
    return 0;
}
