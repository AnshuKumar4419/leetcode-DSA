class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        map<int, int> mp;
        vector<int> score1 = score;
        sort(score1.begin(), score1.end());
        for(int i = 0; i < n; i++) {
            mp[score1[i]] = i;
        }
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            if(mp[score[i]] == n - 1) {
                ans[i] = "Gold Medal";
            } 
            else if(mp[score[i]] == n - 2) {
                ans[i] = "Silver Medal";
            } 
            else if(mp[score[i]] == n - 3) {
                ans[i] = "Bronze Medal";
            } 
            else {
                ans[i] = to_string(n - mp[score[i]]);
            }
        }
        return ans;
    }
};