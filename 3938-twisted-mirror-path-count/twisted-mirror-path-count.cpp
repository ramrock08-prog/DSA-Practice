class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {0, 0}));
        
        dp[0][0] = {1, 1};
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) continue;
                
                long long top_val = (r > 0) ? dp[r - 1][c].first : 0;
                long long left_val = (c > 0) ? dp[r][c - 1].second : 0;
                
                if (grid[r][c] == 1) {
                    dp[r][c] = {left_val, top_val};
                } else {
                    long long total = (top_val + left_val) % MOD;
                    dp[r][c] = {total, total};
                }
            }
        }
        
        return dp[m - 1][n - 1].first;
    }
};