
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mini = min(need1, need2);

        long long ans = mini * min(costBoth, cost1 + cost2);

        ans += (need1 - mini) * min(cost1, costBoth);
        ans += (need2 - mini) * min(cost2, costBoth);

        return ans;
    }
};
