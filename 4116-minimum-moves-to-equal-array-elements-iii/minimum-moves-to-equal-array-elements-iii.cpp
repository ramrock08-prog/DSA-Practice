class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();int count =0;
        int max_term = *max_element(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            count += (max_term -nums[i]);
        }return count;
    }
};