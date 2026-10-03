class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[nums[0]]++;
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) {
                mp[nums[i]]++;
            }
        }
        int ans = 0;
        for(auto x : mp) {
            if(x.second == 1) {
                ans++;
            }
        }
        return ans;
    }
};