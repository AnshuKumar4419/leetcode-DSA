class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        int m = ransomNote.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < n; i++) {
            mp1[magazine[i]]++;
        }
        for(int i = 0; i < m; i++) {
            mp2[ransomNote[i]]++;
        }
        for(auto x : mp2) {
            if(x.second > mp1[x.first]) {
                return false;
            }
        }
        return true;
    }
};