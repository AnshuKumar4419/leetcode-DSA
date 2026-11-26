#include <vector>

class Solution {
private:
    int solve(int n, std::vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];

        int left = solve(n - 1, dp);
        int right = solve(n - 2, dp);
        return dp[n] = left + right;
    }

public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};