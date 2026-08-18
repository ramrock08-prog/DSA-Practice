class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> ram;
        vector<int> jin;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(ram.find(comp) != ram.end()){
               jin.push_back(ram[comp]);
               jin.push_back(i);
            }
            ram[nums[i]] = i;        
        }
        return jin;
    }
};