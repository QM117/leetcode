class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        if(candidates.empty()) return output;
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        count(candidates, target, 0, 0, output, x);
        return output;
    }
    void count(vector<int> candidates, int target, int start, int sum, vector<vector<int>>& output, vector<int> x) {
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i - 1] == candidates[i]) continue;
            if(candidates[i] + sum < target) {
                vector<int> y = x;
                y.push_back(candidates[i]);
                count(candidates, target, i + 1, candidates[i] + sum, output, y);
            }
            else if(candidates[i] + sum == target) {
                cout<<candidates[i]<<" "<<sum<<endl;
                vector<int> y = x;
                y.push_back(candidates[i]); 
                output.push_back(y);
            }
        }
    }
    
};
//两个收获 一个是递归应该把结束条件放在正常递归嵌套外面 不要影响递归的完整性 一个是对于duplicate元素 要比较循环的初始值和当前值 而不是与0比较