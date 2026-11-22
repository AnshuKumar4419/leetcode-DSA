class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') {
                flag = 1;
            }
            if(s[i] == 'a' && flag == 1) {
                return false;
            }
        }
        return true;
    }
};