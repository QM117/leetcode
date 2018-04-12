class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> none;
        vector<int> position;
        none.push_back(-1);
        none.push_back(-1);
        if(nums.empty()) return none;
        int r = nums.size() - 1;
        int l = 0;
        int mid = 0;
        while(1) {
            if(l > r) return none; 
            mid = (r + l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else if(nums[mid] == target) break;
        }
        int L = mid;
        int R = mid;
        cout<<mid<<endl;
        if(L == 0) position.push_back(L);
        else {
            while(L >= 0) {
                if(L == 0 || nums[L - 1] != nums[L]) {
                    position.push_back(L);
                    break;
                }
                L--;
            }
        }
        if(R == nums.size() - 1) position.push_back(R);
        else {
            while(R <= nums.size() - 1) {
                if(R == nums.size() - 1 || nums[R + 1] != nums[R]) {
                    position.push_back(R);
                    break;
                }
                R++;
            }
            
        }
        return position;
    }
};
//可以将-1的边界条件放到while条件里去 这样只要比较当前值与目标 现在的while条件是有冗余的