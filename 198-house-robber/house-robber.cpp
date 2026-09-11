class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev1 = nums[0];
        int prev2 = max(nums[1],nums[0]);
        int result = prev2;
        for(int i=2 ;i<n; i++){
            result = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = result;
        }return result;
    }
};