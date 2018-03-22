class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == val)
                nums.erase(nums.begin() + (i--));
        return nums.size();
    }
};
//想不通为啥直接赋值可以 后面的数据不要裁掉么