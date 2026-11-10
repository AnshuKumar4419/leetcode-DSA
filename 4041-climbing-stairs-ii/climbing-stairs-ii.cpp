class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int jump = 1; jump <= 3; jump++) {
                if (i - jump >= 0) {
                    dp[i] = min(dp[i], dp[i - jump] + costs[i - 1] + 1LL * jump * jump);
                }
            }
        }

        return dp[n];
    }
};