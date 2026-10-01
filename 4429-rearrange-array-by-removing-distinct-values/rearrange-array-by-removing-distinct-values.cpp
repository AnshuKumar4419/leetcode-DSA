class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> ans;
        while(n > 0) {
            for(auto& x : mp) {
                if(x.second > 0) {
                    ans.push_back(x.first);
                    x.second--;
                    n--;
                }
            }
        }
        return ans;
    }
};