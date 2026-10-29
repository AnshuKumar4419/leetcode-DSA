class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != maxi) {
                count--;
                if(count == 0) {
                    maxi = nums[i];
                    count = 1;
                }
            }
            else {
                count++;
            }
        }
        return maxi;
    }
};
