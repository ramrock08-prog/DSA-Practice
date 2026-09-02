class Solution {
public:
void getallsubsets(vector<int>& ans, vector<int>& nums, int i, vector<vector<int>>& allsubsets){
    if(i == nums.size()){
        allsubsets.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getallsubsets(ans,nums,i+1,allsubsets);
    ans.pop_back();
    int idx = i+1;
    while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        getallsubsets(ans,nums,idx,allsubsets);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(ans,nums,0,allsubsets);
        return allsubsets;
    }
};