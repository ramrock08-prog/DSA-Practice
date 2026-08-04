class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(),i;
        vector<int> ans(n,1);
        // prefix
        for(i=1;i<n;i++){
            ans[i] = nums[i-1] * ans[i-1];
        }
        //suffix
        int suffix = 1;
        for(i=n-2;i>=0;i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }
};