class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        int flag = 0;
        while(true) {
            if(k > n) break;
            n -= k--;
            if(flag == 0) flag = 1;
            else flag = 0;
        }
        if(flag == 1) return true;
        return false;
    }
};