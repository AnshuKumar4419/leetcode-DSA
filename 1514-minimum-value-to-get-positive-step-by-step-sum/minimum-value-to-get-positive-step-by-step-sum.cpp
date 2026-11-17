class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        int min_prefix = prefix[0];
        for(int i = 1; i < n; i++) {
            min_prefix = min(min_prefix, prefix[i]);
        }
        
        if (min_prefix < 1) {
            return 1 - min_prefix;
        }
        
        return 1;
    }
};