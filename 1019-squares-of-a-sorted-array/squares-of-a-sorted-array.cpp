class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int pos = n, neg = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                pos = i;
                break;
            }
        }
        neg = pos - 1;
        if(pos < n && nums[pos] == 0) {
            ans.push_back(0);
            pos++;
        }
        while(pos < n && neg >= 0) {
            if(nums[pos] <= abs(nums[neg])) {
                ans.push_back(nums[pos] * nums[pos]);
                pos++;
            }
            else {
                ans.push_back(nums[neg] * nums[neg]);
                neg--;
            }
        }
        while(pos < n) {
            ans.push_back(nums[pos] * nums[pos]);
            pos++;
        }
        while(neg >= 0) {
            ans.push_back(nums[neg] * nums[neg]);
            neg--;
        }

        return ans;
    }
};