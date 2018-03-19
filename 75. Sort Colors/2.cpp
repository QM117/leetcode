class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int len = nums.size();
        int front = 0, back = len - 1, i = 0;
        while(i < back + 1){
            if(nums[i] == 0) exchange(nums,front++,i++);
            else if(nums[i] == 2) exchange(nums,back--,i);
            else i++;
        }
        return;
    }
    void exchange(vector<int>& nums, int a, int b){
        int c = nums[a];
        nums[a] = nums[b];
        nums[b] = c;
        return;
    }
};