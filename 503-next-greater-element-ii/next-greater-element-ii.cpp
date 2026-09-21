class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        stack<int> st;
        for(int i = 0; i < nums.size(); i++) {
            while(st.size() > 0 && nums[i] > nums[st.top()]) {
                nums[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        while(st.size() > 0) {
            nums[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};