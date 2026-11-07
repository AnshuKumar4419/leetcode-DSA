class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(auto x : nums) {
            total_sum += x;
        }
        vector<int> prefix(n + 2);
        prefix[0] = 0;
        prefix[1] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i + 1] = nums[i] + prefix[i];
        }
        prefix[n + 1] = 0;
        for(int i = 1; i < n + 1; i++) {
            if(prefix[i - 1] == total_sum - prefix[i]) {
                return i - 1;
            }
        }
        return -1;
    }
};