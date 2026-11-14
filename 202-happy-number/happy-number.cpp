class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            int m = n;
            int sum = 0;
            while (m > 0) {
                int digit = m % 10;
                sum += (digit * digit);
                m = m / 10;
            }
            n = sum;
        }
        return n == 1;
    }
};