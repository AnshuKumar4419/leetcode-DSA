class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        sort(prefix.begin(), prefix.end());
        if(prefix[0] < 1) return abs(prefix[0]) + 1;
        return 1;
    }
};