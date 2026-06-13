#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    string s;
    int n;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWave[16][10][10];

    pair<ll,ll> solve(int curr, int prevPrev, int prev,
                      bool isLimited, bool isLeadingZero) {

        if(curr == n) return {1, 0};

        if(!isLimited && !isLeadingZero &&
           prevPrev >= 0 && prev >= 0 &&
           dpTotalNumbers[curr][prevPrev][prev] != -1) {

            return {
                dpTotalNumbers[curr][prevPrev][prev],
                dpTotalWave[curr][prevPrev][prev]
            };
        }

        ll totalNumbers = 0;
        ll totalWaveScore = 0;

        int limit = isLimited ? (s[curr] - '0') : 9;

        for(int digit = 0; digit <= limit; digit++) {

            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev, newPrev;

            if(newIsLeadingZero) {
                newPrevPrev = -1;
                newPrev = -1;
            }
            else if(isLeadingZero) {
                // first significant digit
                newPrevPrev = -1;
                newPrev = digit;
            }
            else {
                newPrevPrev = prev;
                newPrev = digit;
            }

            auto [remTotalNumbers, remTotalWaveScore] =
                solve(curr + 1,
                      newPrevPrev,
                      newPrev,
                      isLimited && (digit == limit),
                      newIsLeadingZero);

            totalNumbers += remTotalNumbers;
            totalWaveScore += remTotalWaveScore;

            if(!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {

                bool isPeak   = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if(isPeak || isValley) {
                    totalWaveScore += remTotalNumbers;
                }
            }
        }

        if(!isLimited && !isLeadingZero &&
           prevPrev >= 0 && prev >= 0) {

            dpTotalNumbers[curr][prevPrev][prev] = totalNumbers;
            dpTotalWave[curr][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if(num < 100) return 0;

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWave, -1, sizeof(dpTotalWave));

        s = to_string(num);
        n = (int)s.size();

        auto [totalNumbers, totalWaveScore] =
            solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long a, long long b) {
        return func(b) - func(a - 1);
    }
};

int main() {
    long long a, b;
    cin >> a >> b;

    Solution sol;
    cout << sol.totalWaviness(a, b) << '\n';

    return 0;
}