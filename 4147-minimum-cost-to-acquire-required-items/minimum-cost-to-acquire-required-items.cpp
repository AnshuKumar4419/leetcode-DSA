class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long ans = 0;

        long long mini = min(need1, need2);
        if(costBoth <= (cost1 + cost2)) {
            ans += (mini * costBoth);
            need1 -= mini;
            need2 -= mini;
        }
        if(costBoth <= cost1) ans += (costBoth * need1);
        else ans += (cost1 * need1);

        if(costBoth <= cost2) ans += (costBoth * need2);
        else ans += (cost2 * need2);

        return ans;
    }
};