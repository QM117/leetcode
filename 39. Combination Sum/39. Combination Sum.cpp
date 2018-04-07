class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        if(candidates.empty()) return output;
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        count(candidates, target, 0, output, x);
        return output;      

    }
    void count(vector<int> candidates, int target, int start, vector<vector<int>>& output, vector<int> x) {
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i - 1] == candidates[i]) continue;
            
            if(candidates[i] < target) {
                vector<int> y = x;
                y.push_back(candidates[i]);
                count(candidates, target - candidates[i], i + 1, output, y);
            }
            else if(candidates[i] == target) {
                vector<int> y = x;
                y.push_back(candidates[i]); 
                output.push_back(y);
            }
            if(candidates[i] + candidates[i] == target){
                vector<int> y = x;
                y.push_back(candidates[i]);
                y.push_back(candidates[i]);
                output.push_back(y);
            }
            else if(candidates[i] + candidates[i] < target){
                vector<int> y = x;
                y.push_back(candidates[i]);
                y.push_back(candidates[i]);
                count(candidates, target - candidates[i] - candidates[i], i, output, y);
            }    
        }
    }
};
//加了特殊条件