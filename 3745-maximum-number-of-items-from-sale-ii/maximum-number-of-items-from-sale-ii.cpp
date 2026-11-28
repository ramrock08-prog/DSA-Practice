class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        long long B = budget;

        vector<int> freq(n + 1, 0);
        long long min_price = LLONG_MAX;
        for (const auto& it : items) {
            freq[it[0]]++;
            min_price = min(min_price, static_cast<long long>(it[1]));
        }

        vector<long long> mult_for_factor(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (freq[f] == 0) continue;
            long long total_multiples = 0;
            for (int mult = f; mult <= n; mult += f) {
                total_multiples += freq[mult];
            }
            mult_for_factor[f] = max(0LL, total_multiples - 1);
        }

        struct Batch {
            long long price;
            long long cap; 
        };

        vector<Batch> batches;
        batches.reserve(n);
        for (const auto& it : items) {
            long long p = it[1];
            long long cap = mult_for_factor[it[0]];
            if (cap > 0 && p <= B) {
                batches.push_back({p, cap});
            }
        }
        sort(batches.begin(), batches.end(), [](const Batch& a, const Batch& b) {
            return a.price < b.price;
        });

        long long best_items = B / min_price;
        long long spent = 0;
        long long bonus_items_so_far = 0;

        for (const auto& batch : batches) {
            if (spent + batch.price > B) break;

            long long can_take = min(batch.cap, (B - spent) / batch.price);

            if (can_take > 1) {
                long long s1 = spent + (can_take - 1) * batch.price;
                long long items1 = bonus_items_so_far + (can_take - 1) * 2 + (B - s1) / min_price;
                best_items = max(best_items, items1);
            }

            spent += can_take * batch.price;
            bonus_items_so_far += can_take * 2;
            long long items_full = bonus_items_so_far + (B - spent) / min_price;
            best_items = max(best_items, items_full);

            if (can_take < batch.cap) break;
        }

        return best_items;
    }
};