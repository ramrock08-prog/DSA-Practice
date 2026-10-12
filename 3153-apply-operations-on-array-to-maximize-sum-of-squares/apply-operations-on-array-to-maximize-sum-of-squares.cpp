class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bit_count(31, 0); 
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if ((num >> b) & 1) {
                    bit_count[b]++;
                }
            }
        }
        long long total_sum = 0;
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 0; b < 31; b++) {
                if (bit_count[b] > 0) {
                    val |= (1LL << b); 
                    bit_count[b]--;    
                }
            }
            long long sq = (val % MOD) * (val % MOD) % MOD;
            total_sum = (total_sum + sq) % MOD;
        }

        return total_sum;
    }
};