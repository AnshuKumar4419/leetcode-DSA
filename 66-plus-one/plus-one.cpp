class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        digits[n - 1] += 1;
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] > 9) {
                ans.push_back(0);
                if(i > 0) digits[i - 1] += 1;
            }
            else {
                ans.push_back(digits[i]);
            }
        }
        if(digits[0] > 9) ans.push_back(1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};