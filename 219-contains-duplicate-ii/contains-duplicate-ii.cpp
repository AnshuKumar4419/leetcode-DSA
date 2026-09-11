class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] != 0 && abs(mp[nums[i]] - i - 1) <= k) return true;
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};