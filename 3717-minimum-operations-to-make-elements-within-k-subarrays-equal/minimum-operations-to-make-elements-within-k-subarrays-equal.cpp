#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = 1e18;
        
        vector<long long> windowCost = getWindowCosts(nums, x);
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 2, INF));
        
        for (int i = 0; i <= n + 1; ++i) {
            dp[0][i] = 0;
        }
        
        for (int rem = 1; rem <= k; ++rem) {
            for (int i = 1; i <= n; ++i) {
                long long cost_val = INF;
                if (i >= x) {
                    long long w_cost = windowCost[i - 1];
                    if (w_cost < INF) {
                        cost_val = w_cost + dp[rem - 1][i - x];
                    }
                }
                dp[rem][i] = min(dp[rem][i - 1], cost_val);
            }
        }
        
        return dp[k][n] >= INF ? -1 : dp[k][n];
    }

private:
    vector<long long> getWindowCosts(const vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> costs(n, 1e18);
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }
            
            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }
            
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }
            
            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                costs[i] = ops;
            }
        }
        return costs;
    }
};