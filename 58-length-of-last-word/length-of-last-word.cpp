class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int flag = 0;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ' ' && flag == 0) {
                continue;
            }
            else if(s[i] == ' ' && flag == 1) {
                break;
            }
            else {
                ans++;
                flag = 1;
            }
        }
        return ans;
    }
};