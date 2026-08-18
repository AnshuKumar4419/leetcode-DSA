class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (right - left + 1 == k) {
                unordered_set<int> unique_in_subarray;
                for (int i = left; i <= right; i++) {
                    unique_in_subarray.insert(nums[i]);
                }
                for (int num : unique_in_subarray) {
                    mp[num]++;
                }
                left++;
            }
        }

        int ans = INT_MIN;
        for (const auto& pair : mp) {
            if (pair.second == 1) {
                ans = max(ans, pair.first);
            }
        }

        if (ans == INT_MIN) return -1;
        return ans;
    }
};