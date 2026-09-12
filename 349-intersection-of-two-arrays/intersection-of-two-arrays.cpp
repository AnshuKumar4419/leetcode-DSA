class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            st1.insert(nums1[i]);
        }
        for(int i = 0; i < m; i++) {
            st2.insert(nums2[i]);
        }
        for(auto x : st2) {
            if(st1.find(x) != st1.end()) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};