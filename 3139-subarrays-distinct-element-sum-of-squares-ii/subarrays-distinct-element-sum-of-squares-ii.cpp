class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long count_total = 0;
        long long sq_total = 0;
        long long lazy = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void push(int l, int r, Node* node) {
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();
        
        if (node->lazy != 0) {
            long long x = node->lazy;
            long long len = r - l + 1;
            
            long long new_sq = (node->sq_total + 2 * x * node->count_total + len * x * x) % MOD;
            long long new_cnt = (node->count_total + len * x) % MOD;
            
            node->sq_total = new_sq;
            node->count_total = new_cnt;
            
            if (l != r) {
                node->left->lazy += x;
                node->right->lazy += x;
            }
            node->lazy = 0;
        }
    }

    void update(int l, int r, Node* node, int ql, int qr) {
        push(l, r, node);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            node->lazy += 1;
            push(l, r, node);
            return;
        }
        int mid = l + (r - l) / 2;
        update(l, mid, node->left, ql, qr);
        update(mid + 1, r, node->right, ql, qr);
        
        node->count_total = (node->left->count_total + node->right->count_total) % MOD;
        node->sq_total = (node->left->sq_total + node->right->sq_total) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        Node* root = new Node();
        unordered_map<int, int> lastSeen;
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int l = lastSeen.count(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
            update(0, n - 1, root, l, r);
            lastSeen[nums[r]] = r;
            ans = (ans + root->sq_total) % MOD;
        }

        return ans;
    }
};