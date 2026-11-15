class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        vector<int> freq(26, 0);

        vector<string> ans;

        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a'] = 1;
        }
        for (int i = 0; i < s2.size(); i++) {
            freq[s2[i] - 'a'] = 2;
        }
        for (int i = 0; i < s3.size(); i++) {
            freq[s3[i] - 'a'] = 3;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            char ch = tolower(word[0]);
            int val = freq[ch - 'a'];
            bool flag = true;
            for (int j = 1; j < word.size(); j++) {
                char c = tolower(word[j]);
                if (freq[c - 'a'] != val) {
                    flag = false;
                    break;
                } else {
                    continue;
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};