class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> square(n);
        for(int i=0; i< n; i++){
            square[i] = 1LL * nums[i] * nums[i];
        }sort(square.begin(),square.end());
        long long totalscore = 0;
        int min_count =n/2;
        for(int i=0; i<min_count; i++){
            totalscore -= square[i];
        }for(int i=min_count; i<n; i++){
            totalscore += square[i];
        }return totalscore;
    }
};
