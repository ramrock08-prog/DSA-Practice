class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        vector<vector<int>> semi(n, vector<int>(n, 0));

        for (int d = 1; d <= n / 2; ++d) {
            for (int m = 2; m * d <= n; ++m) {
                int len = m * d;
                for (int i = 0; i + len <= n; ++i) {
                    int j = i + len - 1;
                    
                    int boundary_diff = 0;
                    for (int offset = 0; offset < d; ++offset) {
                        if (s[i + offset] != s[j - d + 1 + offset]) {
                            boundary_diff++;
                        }
                    }

                    int inner = (m > 3) ? semi[i + d][j - d] : 0;
                    semi[i][j] = boundary_diff + inner;
                    
                    cost[i][j] = min(cost[i][j], semi[i][j]);
                }
            }
        }

        vector<int> prev(n + 1, INF);
        prev[0] = 0;

        for (int p = 1; p <= k; ++p) {
            vector<int> curr(n + 1, INF);
            for (int i = 2 * p; i <= n; ++i) {
                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (prev[m] != INF) {
                        curr[i] = min(curr[i], prev[m] + cost[m][i - 1]);
                    }
                }
            }
            prev = move(curr);
        }

        return prev[n];
    }
};