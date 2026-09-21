class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            int flag = 0;
            while(st.size() > 0 && st.top() > 0 && a[i] < 0) {
                if(abs(a[i]) > st.top()) {
                    st.pop();
                } 
                else if(abs(a[i]) == st.top()) {
                    flag = 1;
                    st.pop();
                    break;
                }
                else if(st.top() > abs(a[i])) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) st.push(a[i]);
        }
        vector<int> ans;
        while(st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};