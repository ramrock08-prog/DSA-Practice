class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(),i;
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> ans(n,1);
        // prefix
        for(i=1;i<n;i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }
        //suffix
        for(i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for(i=0;i<n;i++){
        ans[i] = suffix[i] * prefix[i];
        }
        return ans;
    }
};