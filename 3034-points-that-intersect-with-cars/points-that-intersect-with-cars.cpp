class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {vector<int> count(102, 0);

        for (const auto& car : nums) {
            count[car[0]]++;    
            count[car[1] + 1]--;
        }

        int totalPoints = 0;
        int currentCover = 0;

        for (int i = 1; i <= 100; i++) {
            currentCover += count[i];
            if (currentCover > 0) {
                totalPoints++;
            }
        }

        return totalPoints;
    }
};