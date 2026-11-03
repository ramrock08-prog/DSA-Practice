class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto mid_it = nums.begin() + n/2;
        nth_element(nums.begin(), mid_it, nums.end());
        int median = *mid_it;
        long long moves =0;
        for(int num : nums){
            moves += abs((long long)num - median);
        }return moves;
    }
};