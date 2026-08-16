class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long maxi = *max_element(nums.begin(), nums.end()), maxOcc = 0, res = 0;
        int left = 0, right = 0;
        unordered_map<int, int> mp;
        while(right < n) {
            if(nums[right] == maxi) {
                maxOcc++;
            }
            while(maxOcc >= k) {
                if(nums[left] == maxi) {
                    maxOcc--;
                }
                left++;
            }
            res += left;
            right++;
        }
        return res;
    }
};