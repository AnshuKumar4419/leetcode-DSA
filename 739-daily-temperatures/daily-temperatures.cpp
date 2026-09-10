class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> nums(n);

        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                st.push(i);
                nums[i] = 0;
                continue;
            }
            while(!st.empty() && temp[i] >= temp[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                nums[i] = st.top() - i;
            }
            st.push(i);
        }
        return nums;
    }
};