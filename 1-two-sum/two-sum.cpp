class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> ram;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(ram.find(comp) != ram.end()){
               return{ram[comp],i};
            }
            ram[nums[i]] = i;        
        }
        return {};
    }
};