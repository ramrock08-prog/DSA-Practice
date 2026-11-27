class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> mult_count(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    ++mult_count[i];
                }
            }
        }

        struct State {
            int copies = -1;
            int min_price = INT_MAX;
        };

        vector<State> dp(budget + 1);
        dp[0] = {0, INT_MAX};

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int gain = 1 + mult_count[i];

            if (price > budget) continue;

            for (int b = budget - price; b >= 0; --b) {
                if (dp[b].copies == -1) continue;

                int next_b = b + price;
                int next_copies = dp[b].copies + gain;
                int next_min_p = min(dp[b].min_price, price);

                if (next_copies > dp[next_b].copies ||
                    (next_copies == dp[next_b].copies && next_min_p < dp[next_b].min_price)) {
                    dp[next_b] = {next_copies, next_min_p};
                }
            }
        }

        int ans = 0;
        for (int b = 1; b <= budget; ++b) {
            if (dp[b].copies != -1) {
                int extra = (budget - b) / dp[b].min_price;
                ans = max(ans, dp[b].copies + extra);
            }
        }

        return ans;
    }
};