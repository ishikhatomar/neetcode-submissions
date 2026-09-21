class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxWater =0, i=0, j=n-1;
        while(i<j){
            int height = min(heights[i], heights[j]);
            int width = j-i;
            maxWater = max(maxWater, height*width);
            if(heights[i] < heights[j])i++;
            else j--;
        }
        return maxWater;
    }
};
