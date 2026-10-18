class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < t.size() && left < s.size()) {
            if(t[right] != s[left]) {
                right++;
            }
            else {
                left++;
                right++;
                ans++;
            }
        }
        if(ans == s.size()) return true;
        return false;
    }
};