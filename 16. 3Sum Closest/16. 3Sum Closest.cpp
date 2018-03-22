class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int sum = 0;
        if(len <= 3){
            for(int i = 0; i < len; i++)
                sum = sum + nums[i];
            return sum;
        } 
        sum = nums[0] + nums[1] + nums[2];
        if(sum == target) return sum;
        int temp;
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                int k = j + 1;
                temp = nums[rank(nums, k, len - 1, target - nums[i] - nums[j])] + nums[i] + nums[j];
                int y = rank(nums, k, len - 1, target - nums[i] - nums[j]);
                //cout<<i<<"!"<<j<<"!"<<rank(nums, k, len - 1, target - nums[i] - nums[j])<<int((8-5)/2 +5)<<endl;
                if(abs(target - temp) < abs(target - sum)) sum = temp;
            }
        }
        return sum;
    } 
    int rank(vector<int> nums, int k, int len, int target){
        if(k == len) return k;
        int l = k, r = len;
        while(l < r){
            int mid = (r - l) / 2 + l;
            if(nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
            else return mid;
            //cout<<l<<" "<<r<<endl; 
        }
        if(nums[l] == target) return l;
        if(l == k || nums[l] < target){
            if(abs(nums[l] - target) < abs(nums[l + 1] - target)) return l;
            else return l + 1;
        }
        else if(l == len || nums[l] > target){
            if(abs(nums[l] - target) < abs(nums[l - 1] - target)) return l;
            else return l - 1;
        }
    }
};
// 做了一个二分查找。。。