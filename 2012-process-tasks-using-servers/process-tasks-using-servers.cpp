class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }
        
        priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> busy_servers;
        
        vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [free_time, weight, index] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, index});
            }
            
            if (free_servers.empty()) {
                current_time = get<0>(busy_servers.top());
                while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                    auto [free_time, weight, index] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({weight, index});
                }
            }
            
            auto [weight, index] = free_servers.top();
            free_servers.pop();
            
            ans[j] = index;
            busy_servers.push({current_time + tasks[j], weight, index});
        }
        
        return ans;
    }
};