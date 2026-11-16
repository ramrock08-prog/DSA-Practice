class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s;
            next_s.reserve(s.length()); 
            
            for (int i = 0; i < s.length(); i += k) {
                int group_sum = 0;
                int limit = min((int)s.length(), i + k);
                
                for (int j = i; j < limit; ++j) {
                    group_sum += s[j] - '0';
                }
                
                next_s += to_string(group_sum);
            }
            
            s = move(next_s);
        }
        
        return s;
    }
};