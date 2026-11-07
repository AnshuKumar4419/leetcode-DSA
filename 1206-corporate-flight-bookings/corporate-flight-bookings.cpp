class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m = bookings.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < m; i++) {
            int start = bookings[i][0];
            int end = bookings[i][1];
            int seat = bookings[i][2];
            for(int j = start - 1; j < end; j++) {
                ans[j] += seat;
            }
        }
        return ans;
    }
};