class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(auto &x : nums)
            x = 1LL * x * x;

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while(l < r) {
            ans += nums[r]; 
            ans -= nums[l]; 
            r--;
            l++;
        }

        if(l == r)
            ans += nums[r];

        return ans;
    }
};