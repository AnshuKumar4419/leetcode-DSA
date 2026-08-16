class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        long long left = 0, right = 0;
        unordered_map<int, int> mp;
        while(right < n) {
            sum += nums[right];
            mp[nums[right]]++;

            if(right - left + 1 > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }

            if(right - left + 1 == k && mp.size() == k) {
                ans = max(ans, sum);
            }
            right++;
        }
        return ans;
    }
};