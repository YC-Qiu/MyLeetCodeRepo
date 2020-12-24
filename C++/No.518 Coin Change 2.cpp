#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<cstdlib>
#include<deque>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int tempsum = 0;
            for (int c : coins) {
                if (i - c < 0 || dp[i - c] < 0) continue;
                tempsum += dp[i - c];
            }
            dp[i] = tempsum + 1;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        for (int c : coins)if (amount >= c) dp[c] = 1;
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int tempmin = INT_MAX / 2;
            for (int c : coins) {
                if (i - c < 0 || dp[i - c] < 0) continue;
                if (dp[i - c] < tempmin) tempmin = dp[i - c];
            }
            if (tempmin != INT_MAX / 2) dp[i] = tempmin + 1;
        }
        return dp[amount];
    }
};