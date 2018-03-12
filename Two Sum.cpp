class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x = nums.size();
        for (int i = 0; i < x; i++)
        {
            for (int j = i + 1; j < x; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> Position(2);
                    Position[0] = i;
                    Position[1] = j;
                    return Position;
                }
            }
        }
    }
};