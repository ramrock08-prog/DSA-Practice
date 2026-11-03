class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();int max1 =0;int count =0;
        for(int i=0; i<n; i++){
            max1 = max(max1, nums[i]);
        }for(int i=0; i<n; i++){
            int diff = max1 -nums[i];
            count += diff;
        }return count;
    }
};