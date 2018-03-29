class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int divide = 0;
        int len = nums.size();
        for(int i = 1; i < len; i++)
            if(nums[i] < nums[i - 1]){
                divide = i;
                break;
            }
        if(divide == 0) return search(nums, target, 0, len - 1);
        if(nums[0] == target) return 0;
        else if(nums[0] < target) return search(nums, target, 0, divide - 1);
        if(nums[0] > target) return search(nums, target, divide, len - 1);
    }
    int search(vector<int>& nums, int target, int l, int r){
        if(l >= r){
            if(target == nums[l]) return l;
            else return -1;
        }
        int mid = (l + r) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return(search(nums, target, l, mid - 1));
        else return(search(nums, target, mid + 1, r));        
    }
};
//二分查找 所给条件相当于做了一次二分查找