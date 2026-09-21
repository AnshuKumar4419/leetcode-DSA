class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> st;
        for(int i = 0; i < n; i++) {
            int flag = 0;
            while(st.size() > 0 && st.back() > 0 && a[i] < 0) {
                if(abs(a[i]) > st.back()) {
                    st.pop_back();
                } 
                else if(abs(a[i]) == st.back()) {
                    flag = 1;
                    st.pop_back();
                    break;
                }
                else if(st.back() > abs(a[i])) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) st.push_back(a[i]);
        }
        return st;
    }
};