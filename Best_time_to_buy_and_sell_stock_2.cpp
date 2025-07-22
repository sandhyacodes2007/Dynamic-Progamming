#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, long *values, int n, vector<vector<long>> &dp) {
    if (ind == n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;
    if (buy) {
        profit = max(-values[ind] + func(ind + 1, 0, values, n, dp), func(ind + 1, 1, values, n, dp));
    } else {
        profit = max(values[ind] + func(ind + 1, 1, values, n, dp), func(ind + 1, 0, values, n, dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n) {
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return func(0, 1, values, n, dp);
}

int main() {
    int n;
    cin >> n;
    vector<long> a(n); // Use long to match function parameter

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << getMaximumProfit(a.data(), n) << endl; // Pass correct parameters
}