class Solution {
    public:
        double minPrice(vector<int>& prices, vector<int>& discounts) {
            sort(prices.begin(), prices.end());
            sort(discounts.begin(), discounts.end());

            int n = prices.size();
            int m = discounts.size();
            int k = min(n, m);

            double ans = 0.0;
            int j = m - 1;

            for (int i = n - 1; i >= n - k; --i) {
                ans += (double)prices[i] * (100 - discounts[j]) / 100.0;
                --j;
            }

            for (int i = 0; i < n - k; ++i) {
            ans += prices[i];
        }

        return ans;
    }
                                                                                                                                    
};
