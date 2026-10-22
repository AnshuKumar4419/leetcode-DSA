class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int,int>> visited;      
        vector<int> ans = {0, 0};
        int i = 0, j = 0;
        visited.insert({0, 0});

        while (true) {
            if      (grid[i][j] == 'R') j++;
            else if (grid[i][j] == 'L') j--;
            else if (grid[i][j] == 'D') i++;
            else if (grid[i][j] == 'U') i--;

            if (i < 0 || i >= n || j < 0 || j >= m) return ans;
            if (visited.count({i, j})) return ans;

            ans = {i, j};
            visited.insert({i, j});
        }
    }
};