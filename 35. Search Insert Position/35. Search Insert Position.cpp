class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int r = nums.size() - 1;
        int l = 0;
        
        while(1) {
            if(l > r) return l; 
            int mid = (r + l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else if(nums[mid] == target) return mid;
        }

    }
};