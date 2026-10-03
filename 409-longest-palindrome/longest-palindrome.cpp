class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int ans = 0;
        int maxi = 0;
        int odd = 0;
        for(auto& x : mp) {
            if(x.second % 2 == 0) {
                ans += x.second;
            } else {
                ans += x.second - 1;
                odd = 1;
            }
        }
        if(odd) return ans + 1;
        return ans;
    }
};