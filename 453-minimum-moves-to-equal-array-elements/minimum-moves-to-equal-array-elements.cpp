class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min_value = *min_element(nums.begin(), nums.end());
        long long sum =0;
        for(int num : nums){
            sum += num;
        }return sum - min_value * n;
    }
};