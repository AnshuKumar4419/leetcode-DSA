class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);

        long long inversions = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (nums[i] > nums[j]) {
                    inversions++;

                    diff[i]++;
                    diff[j + 1]--;
                }
            }
        }
        int unlocks = 0;
        int active = 0;

        for (int i = 0; i < n; i++) {
            active += diff[i];

            if (active > 0 && locked[i] == 1) {
                unlocks++;
            }
        }

        if (unlocks > k) {
            return -1;
        }

        return inversions + unlocks;
    }
};