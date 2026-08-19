class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<int> freq(n*n+1,0);
       int a=-1,b=-1;
       for(auto& row : grid){
        for(int x : row){
            freq[x]++;
        }
       }
       for (int i = 1; i <= n * n; i++){
        if(freq[i] == 0)
        b = i;
       else if (freq[i] == 2)
        a = i;
       }return {a,b};
    }
};