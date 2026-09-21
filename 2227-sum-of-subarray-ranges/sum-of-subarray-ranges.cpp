class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long minSum = sumSubarrayMin(nums, n);
        long long maxSum = sumSubarrayMax(nums, n);

        return maxSum - minSum;
    }

    long long sumSubarrayMin(vector<int>& nums, int n) {
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += 1LL * nums[i] * left[i] * right[i];

        return ans;
    }

    long long sumSubarrayMax(vector<int>& nums, int n) {
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += 1LL * nums[i] * left[i] * right[i];

        return ans;
    }
};
