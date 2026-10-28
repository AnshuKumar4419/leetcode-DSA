class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int d = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                d++;
            }
            else {
                d = 0;
            }
            ans = max(ans, d);
        }
        return ans;
    }
};