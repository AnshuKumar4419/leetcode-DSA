class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int count = 0;

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int mod = prefixSum % k;

            if(mod < 0) {
                mod += k;
            }

            if(mp.find(mod) != mp.end()) {
                count += mp[mod];
                mp[mod]++;
            }
            else {
                mp[mod]++;
            }
        }
        return count;
    }
};