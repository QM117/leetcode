class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        sort(nums.begin(), nums.end());
        int index_t = 0;
        int index_temp = 0;
        int index_temp2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = res.size();
            index_temp2 = index_temp;
            index_temp = 0;
            //cout<<n<<endl;
            if(i > 0 && nums[i] == nums[i - 1]) {
                //cout<<index_t<<","<<n<<endl;
                for(int j = index_t + 1; j < n; j++) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                    index_temp++; 
                }
            }
            else {
                for (int j = 0; j < n; j++) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                    index_temp++;
                }              
            }
            index_t += index_temp2;
        }
        return res;
    }
};
//在1的基础上改的