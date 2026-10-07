class Solution {
private:
    unordered_set<string> valid_set;

    void dfs(const string& s, int index, int open_rem, int close_rem, int balance, string& current) {
        if (balance < 0 || open_rem < 0 || close_rem < 0) return;

        if (index == s.length()) {
            if (open_rem == 0 && close_rem == 0 && balance == 0) {
                valid_set.insert(current);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            dfs(s, index + 1, open_rem - 1, close_rem, balance, current);

            current.push_back('(');
            dfs(s, index + 1, open_rem, close_rem, balance + 1, current);
            current.pop_back(); 
        } 
        else if (c == ')') {
            dfs(s, index + 1, open_rem, close_rem - 1, balance, current);

            current.push_back(')');
            dfs(s, index + 1, open_rem, close_rem, balance - 1, current);
            current.pop_back(); 
        } 
        else {
            current.push_back(c);
            dfs(s, index + 1, open_rem, close_rem, balance, current);
            current.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int open_rem = 0;
        int close_rem = 0;

        for (char c : s) {
            if (c == '(') {
                open_rem++;
            } else if (c == ')') {
                if (open_rem > 0) {
                    open_rem--;
                } else {
                    close_rem++;
                }
            }
        }

        string current = "";
        dfs(s, 0, open_rem, close_rem, 0, current);

        return vector<string>(valid_set.begin(), valid_set.end());
    }
};