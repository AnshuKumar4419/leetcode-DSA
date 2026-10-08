class Solution {
public:
    string reverseVowels(string s) {
        int right = s.size() - 1;
        int left = 0;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        while(left < right) {
            if(st.find(s[left]) == st.end()) left++;
            if(st.find(s[right]) == st.end()) right--;
            if(st.find(s[left]) != st.end() && st.find(s[right]) != st.end()) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};