class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = 0; i < n2; i++) {
            while(st.size() > 0 && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(st.size() > 0) {
            mp[nums2[st.top()]] = -1;
            st.pop();
        }
        vector<int> ans;
        for(int i = 0; i < n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};