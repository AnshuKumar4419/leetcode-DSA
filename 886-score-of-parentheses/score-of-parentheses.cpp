class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); 

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();
                int currentVal = 0;
                if(innerScore == 0) {
                     currentVal = 1;
                }
                else {
                    currentVal = 2 * innerScore;
                }
                st.top() += currentVal;
            }
        }

        return st.top();
    }
};