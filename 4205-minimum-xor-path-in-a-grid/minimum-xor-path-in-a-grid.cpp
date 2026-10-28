class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        dp [ 0 ] [ 0 ] [ grid [ 0 ] [ 0 ] ] = true;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                bool reachable = false;
                for (int x = 0; x < 1024; ++x) {
                    if (dp[r][c][x]) {
                        reachable = true;
                        break;
                    }
                }
                if (!reachable && !(r == 0 && c == 0)) continue;
                if (r + 1 < m) {
                    int next_val = grid[r + 1][c];
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[r][c][x]) {
                            dp[r + 1][c][x ^ next_val] = true;
                        }
                    }
                }
                if (c + 1 < n) {
                    int next_val = grid[r][c + 1];
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[r][c][x]) {
                            dp[r][c + 1][x ^ next_val] = true;
                        }
                    }
                }
            }
        }
        for (int x = 0; x < 1024; ++x) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }
        
        return 0;
    }
};