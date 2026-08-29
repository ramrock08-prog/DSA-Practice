class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0, n=height.size();
        int l=0,r=n-1;
        while(l<r){
            int w = r-l;
            int h = min(height[l], height[r]);
            int area = w*h;
            max_water = max(max_water,area);
            height[l]<height[r] ? l++ : r--;
        }
       return max_water; 
    }
};