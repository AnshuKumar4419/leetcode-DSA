class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            unordered_set<char> st;
            st.insert(s[i]);
            st.insert(s[i + 1]);
            st.insert(s[i + 2]);
            if(st.size() == 3) ans++;
        }
        return ans;
    }
};