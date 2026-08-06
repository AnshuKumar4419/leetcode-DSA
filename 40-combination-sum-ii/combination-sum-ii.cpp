class Solution {
public:
    void solve(int ind, int sum, vector<int> &temp, vector<vector<int>> &ans, vector<int>& cand, int target) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(ind >= cand.size() || sum > target) {
            return;
        }
        // take
        temp.push_back(cand[ind]);
        solve(ind + 1, sum + cand[ind], temp, ans, cand, target);
        temp.pop_back();
        while(ind + 1 < cand.size() && cand[ind] == cand[ind + 1]) {
            ind++;
        }
        // not take
        solve(ind + 1, sum, temp, ans, cand, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, 0, temp, ans, cand, target);
        return ans;
    }
};