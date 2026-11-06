class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q_len = queries.size();
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> indexed_queries(q_len);
        for (int i = 0; i < q_len; ++i) {
            indexed_queries[i] = {queries[i], i};
        }
        
        sort(indexed_queries.begin(), indexed_queries.end());
        
        vector<int> ans(q_len);
        vector<int> server_count(n + 1, 0);
        int active_servers = 0;
        
        int log_left = 0, log_right = 0;
        
        for (const auto& [q_time, orig_idx] : indexed_queries) {
            int R = q_time;
            int L = q_time - x;
            
            while (log_right < m && logs[log_right][1] <= R) {
                int s_id = logs[log_right][0];
                if (server_count[s_id] == 0) {
                    active_servers++;
                }
                server_count[s_id]++;
                log_right++;
            }
            while (log_left < log_right && logs[log_left][1] < L) {
                int s_id = logs[log_left][0];
                server_count[s_id]--;
                if (server_count[s_id] == 0) {
                    active_servers--;
                }
                log_left++;
            }
            
            ans[orig_idx] = n - active_servers;
        }
        
        return ans;
    }
};