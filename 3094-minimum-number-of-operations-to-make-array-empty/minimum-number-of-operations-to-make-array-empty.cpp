class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int cnt = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                cnt++;
            }
            else {
                if(cnt == 1) return -1;
                if(cnt % 3 == 0) ans += cnt / 3;
                else if(cnt % 3 == 2) ans += (cnt / 3) + 1;
                else ans += (cnt / 3) + 1;
                cnt = 1;
            }
        }
        if(cnt == 1) return -1;
        if(cnt % 3 == 0) ans += cnt / 3;
        else if(cnt % 3 == 2) ans += (cnt / 3) + 1;
        else ans += (cnt / 3) + 1;

        return ans;
    }
};