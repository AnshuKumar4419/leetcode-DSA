class Solution {
public:
    int largestInteger(int n, int s) {
        string t;
        for(int i = 0; i < n; i++) {
            if(s >= 9) {
                t.push_back('9');
                s -= 9;
            }
            else if(s >= 1) {
                t += to_string(s);
                s = 0;
            }
            else {
                t.push_back('0');
            }
        }
        if(s > 0) return -1;
        return stoi(t);
    }
};