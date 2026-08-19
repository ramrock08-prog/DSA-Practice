class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        vector<int> ans;
        int actsum=0, expsum=0;
        int i,a,b, n = grid.size();
        for(i = 0; i<n; i++){
            for(int j=0; j<n;j++){
                actsum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expsum = ((n*n)*(n*n + 1))/2;
        b = expsum + a - actsum;
        ans.push_back(b);
        return ans;
    }
};