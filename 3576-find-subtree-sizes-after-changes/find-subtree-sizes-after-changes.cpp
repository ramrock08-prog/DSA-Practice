class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent(n, -1);
        array<int, 26> last_seen;
        last_seen.fill(-1);

        auto find_parents = [&](auto& self, int u) -> void {
            int ch = s[u] - 'a';
            int prev_ancestor = last_seen[ch];
            new_parent[u] = (prev_ancestor != -1) ? prev_ancestor : parent[u];

            last_seen[ch] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            last_seen[ch] = prev_ancestor;
        };

        find_parents(find_parents, 0);

        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        vector<int> subtree_size(n, 1);
        auto calc_sizes = [&](auto& self, int u) -> void {
            for (int v : final_adj[u]) {
                self(self, v);
                subtree_size[u] += subtree_size[v];
            }
        };

        calc_sizes(calc_sizes, 0);
        return subtree_size;
    }
};