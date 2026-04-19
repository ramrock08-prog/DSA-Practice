class Solution {
public:
    bool searchMatrix(vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            int currentVal = matrix[row][col];
            
            if (currentVal == target) {
                return true;
            } 
            else if (currentVal > target) {
                col--; 
            } 
            else {
                row++;
            }
        }
        
        return false;
    }
};