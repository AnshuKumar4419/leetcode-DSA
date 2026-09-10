class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> nums(n, 0);

        // Traverse backwards from the second-to-last element
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;

            // Jump forward using already computed answer values
            while (j < n && temp[j] <= temp[i]) {
                if (nums[j] == 0) {
                    j = n; // No warmer day exists ahead
                    break;
                }
                j += nums[j]; // Jump straight to the next warmer day
            }

            // If a warmer day was found within bounds
            if (j < n) {
                nums[i] = j - i;
            }
        }

        return nums;
    }
};