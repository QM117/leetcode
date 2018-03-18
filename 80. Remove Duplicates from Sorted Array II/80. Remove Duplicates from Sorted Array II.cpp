class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int flag = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i] && flag == 0){
                flag = 1;
                continue;
            }
            else if(nums[i - 1] == nums[i] && flag == 1){
                cout<<"!"<<endl;
                nums.erase(nums.begin() + (i--));
                continue;
            }
            else flag = 0;
        }
        return nums.size();
    }
};
//因为LeetCode·中显示要输出结果 我就想着必须将向量移除掉 结果并不需要···所以移除向量可以去掉。。。 第二个方法是 由于序列是有序的 所以含有可比较的信息 可以直接将向后2位的值直接赋值到对应位置来求得数组 但 不知道 如果有重复的 怎么将顺移到最后的删去··· 3是按照别人的想法自己写的 主要还是要注意index的位置是与i不同的 比较的也是index-2的比较 而不是i-2的比较
