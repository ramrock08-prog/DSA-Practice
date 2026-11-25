class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1) return 1;

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = static_cast<int>(lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin());
        }

        vector<int> sa(n), rnk(a), tmp(n);
        iota(sa.begin(), sa.end(), 0);

        for (int step = 1; step < n; step <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
                int ri = (i + step < n) ? rnk[i + step] : -1;
                int rj = (j + step < n) ? rnk[j + step] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            rnk.swap(tmp);
            if (rnk[sa[n - 1]] == n - 1) break;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[sa[i]] = i;

        vector<int> lcp(max(0, n - 1), 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (pos[i] == 0) {
                h = 0;
                continue;
            }
            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && a[i + h] == a[j + h]) {
                ++h;
            }
            lcp[pos[i] - 1] = h;
            if (h > 0) --h;
        }

        int ans = n;
        for (int idx = 0; idx < n; ++idx) {
            int max_dup = 0;
            if (idx > 0) max_dup = max(max_dup, lcp[idx - 1]);
            if (idx + 1 < n) max_dup = max(max_dup, lcp[idx]);

            int rem_len = n - sa[idx];
            if (max_dup + 1 <= rem_len) {
                ans = min(ans, max_dup + 1);
            }
        }

        return ans;
    }
};