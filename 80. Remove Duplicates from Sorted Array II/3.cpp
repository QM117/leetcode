class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size(); 
        if(len < 3) return len;
        int index = 2;
        for(int i = 2; i < len; i++){
            if(nums[index - 2] != nums[i]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};