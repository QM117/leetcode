class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int max = 0;
        int rect = 0;
        int min = 0;
        for(int i = 0; i < heights.size(); i++) {
            

            for(int j = i; j < heights.size(); j++) {
                if(j == i) {
                    rect = heights[i];
                    if(rect > max) max = rect;
                    min = heights[i];
                }
                else if(heights[j] <= min) {
                    min = heights[j];
                    rect = (j - i + 1) * min;
                    if(rect > max) max = rect;
                }
                else if(heights[j] > min) {
                    rect = (j - i + 1) * min;
                    if(rect > max) max = rect;
                }
            }
        }
        return max;
    }
};
//以前可能做过 用的循环没用栈