class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            mini += (mx - nums[i]);
        }
        return mini;
    }
};