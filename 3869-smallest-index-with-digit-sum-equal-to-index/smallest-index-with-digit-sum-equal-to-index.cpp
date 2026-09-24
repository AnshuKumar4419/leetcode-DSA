class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int digit = 0;
            while(nums[i] > 0) {
                int curr = nums[i] % 10;
                digit += curr;
                nums[i] = nums[i] / 10;
            }
            if(digit == i) {
                return i;
            }
        }
        return -1;
    }
};