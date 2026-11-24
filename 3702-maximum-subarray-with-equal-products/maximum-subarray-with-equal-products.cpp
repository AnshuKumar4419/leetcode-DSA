class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mask[11] = {0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5};

        int n = nums.size();
        int used = 0, l = 0;
        int ans = 2;  

        for (int r = 0; r < n; r++) {
            while (used & mask[nums[r]]) {
                used ^= mask[nums[l]];
                l++;
            }
            used |= mask[nums[r]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};