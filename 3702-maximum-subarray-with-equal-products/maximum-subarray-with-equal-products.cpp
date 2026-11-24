class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            long long cur_gcd = 0;
            long long cur_lcm = 1;
            long long cur_prod = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];

                if (cur_prod > LLONG_MAX / val) {
                    break;
                }

                cur_prod *= val;
                cur_gcd = (cur_gcd == 0) ? val : std::gcd(cur_gcd, val);
                cur_lcm = std::lcm(cur_lcm, val);

                if (cur_lcm > LLONG_MAX / cur_gcd) {
                    break;
                }

                if (cur_prod == cur_lcm * cur_gcd) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};