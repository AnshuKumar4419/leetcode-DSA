class Solution {
public:
    
    void solve(int ind, vector<int> temp, vector<vector<int>>& ans, vector<int>& nums) {
        if(ind >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        // take
        temp.push_back(nums[ind]);
        solve(ind + 1, temp, ans, nums);

        // not take
        temp.pop_back();
        solve(ind + 1, temp, ans, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, temp, ans, nums);
        return ans;
    }
};