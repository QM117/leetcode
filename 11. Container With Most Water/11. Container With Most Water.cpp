class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int cap = 0;
        int water = min(height[l],height[r]) * (len - 1);
        while(l < r){
            int h = min(height[l], height[r]);
            cap = min(height[l],height[r]) * (r - l);
            if(cap > water) water = cap;
            while(height[l] <= h && l < r) l++;
            while(height[r] <= h && l < r) r--;
        }
        return water;
    }
};
//别人的方法 先求最宽的 然后在对比 有隐含的递归思想