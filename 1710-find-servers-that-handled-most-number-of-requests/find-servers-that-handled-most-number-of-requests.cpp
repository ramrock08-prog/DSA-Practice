class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> request_count(k, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        
        set<int> free_servers;
        for (int i = 0; i < k; ++i) {
            free_servers.insert(i);
        }
        
        for (int i = 0; i < n; ++i) {
            long long curr_arrival = arrival[i];
            long long curr_load = load[i];
            while (!busy_servers.empty() && busy_servers.top().first <= curr_arrival) {
                free_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            if (free_servers.empty()) {
                continue;
            }
            
            int target = i % k;
            auto it = free_servers.lower_bound(target);
            
            if (it == free_servers.end()) {
                it = free_servers.begin();
            }
            
            int assigned_server = *it;
            free_servers.erase(it);
            
            request_count[assigned_server]++;
            busy_servers.push({curr_arrival + curr_load, assigned_server});
        }
        
        int max_requests = *max_element(request_count.begin(), request_count.end());
        vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};