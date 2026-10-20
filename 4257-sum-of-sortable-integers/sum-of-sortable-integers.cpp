class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        auto isSortable = [&](int k) {
            for (int i = 0; i < n; i += k) {
                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                vector<int> target(s.begin() + i, s.begin() + i + k);
                int drops = 0;
                for (int j = 0; j < k; ++j) {
                    if (block[j] > block[(j + 1) % k]) {
                        drops++;
                    }
                }
                if (drops > 1) return false;
                vector<int> sortedBlock = block;
                sort(sortedBlock.begin(), sortedBlock.end());
                if (sortedBlock != target) return false;
            }
            return true;
        };

        int totalSum = 0;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(k)) {
                    totalSum += k;
                }
                int other = n / k;
                if (other != k && isSortable(other)) {
                    totalSum += other;
                }
            }
        }
        
        return totalSum;
    }
};