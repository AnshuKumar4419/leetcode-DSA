class Solution {
public:
    void solve(int ind, int sum, vector<int>& temp, vector<vector<int>>& ans, int k, int n, vector<int>& nums) {
        if(sum == n) {
            if(temp.size() == k) ans.push_back(temp);
            return;
        }
        if(temp.size() > k || ind >= nums.size() || sum > n) {
            return;
        }
        // take
        temp.push_back(nums[ind]);
        solve(ind + 1, sum + nums[ind], temp, ans, k, n, nums);

        temp.pop_back();

        // not take
        solve(ind + 1, sum, temp, ans, k, n, nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 0; i < 9; i++) {
            nums.push_back(i + 1);
        }
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, 0, temp, ans, k, n, nums);
        return ans;
    }
};