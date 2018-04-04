class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int divide = 0;
        int len = nums.size();
        for(int i = 1; i < len; i++)
            if(nums[i] < nums[i - 1]){
                divide = i;
                break;
            }
        if(divide == 0) return search(nums, target, 0, len - 1);
        if(nums[0] == target) return true;
        else if(nums[0] < target) return search(nums, target, 0, divide - 1);
        if(nums[0] > target) return search(nums, target, divide, len - 1);
    }
    bool search(vector<int>& nums, int target, int l, int r){
        if(l >= r){
            if(target == nums[l]) return true;
            else return false;
        }
        int mid = (l + r) / 2;
        if(nums[mid] == target) return true;
        else if(nums[mid] > target) return(search(nums, target, l, mid - 1));
        else return(search(nums, target, mid + 1, r));        
    }
};
//没有任何变化 将int改成bool 这里用遍历找翻转点所用时间太多了 别人是直接用二分查找的