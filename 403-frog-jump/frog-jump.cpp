class Solution {
public:
    bool canCross(vector<int>& stones) {

        // Stores all possible jump sizes at each stone
        unordered_map<int, unordered_set<int>> dp;

        // Initially, frog is at stone 1 and can jump 1 unit
        dp[1].insert(1);

        // Traverse all stones
        for (int i = 1; i < stones.size(); i++) {

            int currentStone = stones[i];

            for (int jump : dp[currentStone]) {

                int nextJump = jump;
                dp[currentStone + nextJump].insert(nextJump);

                nextJump = jump + 1;
                dp[currentStone + nextJump].insert(nextJump);

                nextJump = jump - 1;

                if (nextJump > 0) {
                    dp[currentStone + nextJump].insert(nextJump);
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};