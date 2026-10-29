class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    int n;

    void dfs(int u, int p, int current_xor, const vector<vector<int>>& adj, const string& s, vector<int>& node_path_xor) {
        tin[u] = ++timer;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);
        up[u][0] = (p == -1 ? u : p);
        for (int i = 1; i < 17; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        current_xor ^= (1 << (s[u] - 'a'));
        node_path_xor[timer] = current_xor;

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, current_xor, adj, s, node_path_xor);
            }
        }
        tout[u] = timer;
    }

    void bit_update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int bit_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = 16; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 16; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        timer = 0;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        tin.resize(n + 1);
        tout.resize(n + 1);
        depth.resize(n);
        up.assign(n, vector<int>(17, 0));
        bit.assign(n + 2, 0);

        vector<int> node_path_xor(n + 1, 0);
        dfs(0, -1, 0, adj, s, node_path_xor);
        vector<int> diff(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            diff[i] = node_path_xor[i] ^ node_path_xor[i - 1];
            bit_update(i, diff[i]);
        }

        vector<bool> answer;
        answer.reserve(queries.size());

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                char old_c = s[u];
                if (old_c != c) {
                    int delta = (1 << (old_c - 'a')) ^ (1 << (c - 'a'));
                    s[u] = c;
                    bit_update(tin[u], delta);
                    bit_update(tout[u] + 1, delta);
                }
            } else {
                int u, v;
                ss >> u >> v;

                int lca = get_lca(u, v);
                int mask_u = bit_query(tin[u]);
                int mask_v = bit_query(tin[v]);
                int mask_lca = 1 << (s[lca] - 'a');

                int path_mask = mask_u ^ mask_v ^ mask_lca;
                bool is_palindrome = (path_mask == 0) || ((path_mask & (path_mask - 1)) == 0);
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};