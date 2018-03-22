class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return 1;
        int j = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] != nums[j])
                nums[++j] = nums[i];
        return j+1;
    }
};