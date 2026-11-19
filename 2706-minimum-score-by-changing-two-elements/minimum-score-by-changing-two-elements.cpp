#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int drop_two_largest  = nums[n - 3] - nums[0];
        int drop_two_smallest = nums[n - 1] - nums[2];
        int drop_one_each     = nums[n - 2] - nums[1];
        
        return min({drop_two_largest, drop_two_smallest, drop_one_each});
    }
};