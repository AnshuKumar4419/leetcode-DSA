class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalCount = 0;
        int realCount = 0;
        int n = nums.size();

        for(int i = 1; i <= n; i++) {
            totalCount += i;
        }
        for(int i = 0; i < n; i++) {
            realCount += nums[i];
        }
        return totalCount - realCount;
    }
};