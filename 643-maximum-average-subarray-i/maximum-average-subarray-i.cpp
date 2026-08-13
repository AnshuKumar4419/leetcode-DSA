class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = 0;
        int sum = 0;
        double ans = INT_MIN;
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n) {
            sum += nums[right];
            curr++;
            if(curr == k) {
                ans = max(ans, ((double)sum)/(k));
                sum -= nums[left++];
                curr--;
            }
            right++;
        }
        return ans;
    }
};