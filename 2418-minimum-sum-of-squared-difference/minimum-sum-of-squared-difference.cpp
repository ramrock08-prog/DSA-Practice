class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        int max_diff = 0;
        vector<long long> freq(100001,0);

        for(int i = 0; i< n; i++){
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            max_diff = max(max_diff,diff);
        }
        for(int d = max_diff; d>0 && k>0; d--){
            if(freq[d] == 0) continue;
            long long take = min(k,freq[d]);
            freq[d] -= take;
            freq[d-1] += take;
            k -= take;
        }
        long long ans = 0;
        for(int d = 1; d <= max_diff; d++){
            if(freq[d] > 0){
                ans += freq[d] * (long long)d*d;
            }
        }return ans;
    }
};