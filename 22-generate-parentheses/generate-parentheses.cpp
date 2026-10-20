class Solution {
private:
    void backtrack(string& curr, int opencount, int closecount, int n, vector<string>& result){
        if(curr.length() == 2*n){
            result.push_back(curr);
            return;
        }if(opencount < n){
            curr.push_back('(');
            backtrack(curr, opencount + 1, closecount, n, result);
            curr.pop_back();
        }if(opencount > closecount){
            curr.push_back(')');
            backtrack(curr, opencount , closecount + 1, n, result);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        backtrack(curr, 0 , 0, n, result);
        return result;
    }
};