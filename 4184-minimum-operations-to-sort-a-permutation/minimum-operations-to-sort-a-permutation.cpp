class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        for(int i =0; i<n; i++){
            if(nums[i] == 0){
                zero =i;
                break;
            }
        }
        auto check = [&](int step){
            for(int i =1; i<n; i++){
                int pre = (zero +(i-1) * step) % n;
                if(pre <0) pre += n;
                int curr = (zero + i* step) % n;
                if(curr < 0) curr += n;
                if(nums[pre] > nums[curr]){
                    return false;
                }
            }
            return true;
        };
        int ans= INT_MAX;
        if(check(1)){
            ans = min(zero, ans);
            ans = min(n-zero+2, ans);
        }
        if(check(-1)){
            ans = min(zero + 2, ans);
            ans = min(ans, n-zero);
        }
        return ans == INT_MAX ? -1 :ans;
    }
};