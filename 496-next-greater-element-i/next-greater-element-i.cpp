class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int Greater = -1;
            int found = 0;
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j]) {
                    found = 1;
                }
                if(nums1[i] < nums2[j] && found == 1) {
                    Greater = nums2[j];
                    break;
                }
            }
            ans.push_back(Greater);
        }
        return ans;
    }
};
