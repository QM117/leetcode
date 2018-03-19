class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int len = nums.size();
        int front = 0, back = len - 1;
        for(int i = 0; i < len; i++){
            while(nums[front] == 0) front++;
            while(nums[back] == 2) back--;
            if(nums[i] == 0 && i > front) exchange(nums,front,i);
            if(nums[i] == 2 && i < back) exchange(nums,back,i);
            if(nums[i] == 0 && i > front) exchange(nums,front,i);
            if(nums[i] == 2 && i < back) exchange(nums,back,i);
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
//想法和别人一样 但是还是边界条件 自己想的是将头尾指向先推到需要交换的部分 结果边界条件就控制不好了 其实可以不管头尾的指向 每次都交换就行 2是按照别人的思想自己写的 其中2的循环是对应着小于尾部+1 控制边界 由于是从开头一个一个交换 所以不存在交换出2在交换出0 因为 在遇到0之前已经没有2了