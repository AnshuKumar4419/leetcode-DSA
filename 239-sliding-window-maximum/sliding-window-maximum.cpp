class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        
        int right = 0, left = 0;
        vector<int> ans;
        int maxi = nums[0];

        while(right < n) {
            mp[nums[right]]++;
            if(right - left + 1 > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            if(right - left + 1 == k) {
                auto last_element = mp.rbegin();
                ans.push_back(last_element->first);
            }
            right++;
        }
        return ans;
    }
};