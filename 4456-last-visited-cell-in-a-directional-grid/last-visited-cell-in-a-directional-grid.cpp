class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0 || grid[0].empty())
            return {-1, -1};

        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int i = 0, j = 0;
        visited[i][j] = true;

        while (true) {
            int ni = i, nj = j;

            if (grid[i][j] == 'R') nj++;
            else if (grid[i][j] == 'L') nj--;
            else if (grid[i][j] == 'D') ni++;
            else if (grid[i][j] == 'U') ni--;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m ||
                visited[ni][nj]) {
                return {i, j};
            }

            i = ni;
            j = nj;
            visited[i][j] = true;
        }
    }
};