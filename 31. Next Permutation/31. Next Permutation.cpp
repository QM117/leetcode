class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int len = nums.size();
        if(len == 1) return;
        for(int i = len - 1; i > 0 ; i--){
            if(nums[i] > nums[i - 1]){
                cout<<"!"<<endl;
                for(int j = len - 1; j >= i ; j--){
                    if(nums[j] > nums[i - 1]){
                        swap(nums[j],nums[i - 1]);
                        break;
                    }                                
                }
                for(int j = 0; j <int ((len - i)/2); j++)
                    swap(nums[i+j],nums[len - 1 - j]);
                return;
            }
        }
        for(int i = 0; i < len/2; i++)
            swap(nums[i],nums[len - 1 - i]);
        return;
    }
};
//看起来 还阔以 就是原来还有reverse函数。。。