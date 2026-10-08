class Solution {
public:
    set<vector<int>> s;
    void getallcomb(vector<int>& candidates, int idx, int target, vector<vector<int>>& ans, vector<int>& comb){
        if(idx == candidates.size() || target < 0) {
            return;
        }
        if(target == 0){
            if(s.find(comb) == s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }
        comb.push_back(candidates[idx]);
        getallcomb(candidates, idx+1, target - candidates[idx], ans, comb);
        getallcomb(candidates, idx, target - candidates[idx], ans, comb);
        comb.pop_back();
        getallcomb(candidates, idx+1, target, ans, comb);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        getallcomb(candidates, 0, target, ans, comb);
        return ans;
    }
};