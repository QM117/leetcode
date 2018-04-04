class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> target;
        
        if(n < k || k == 0) return target;
        for(int i = 1; i <= n - k + 1 ; i++) {
            vector<int> sub;
            sub.push_back(i);
            Combine(n, k - 1, i, target, sub);
        }
        return target;
    }
    void Combine(int n, int k, int f, vector<vector<int>>& target, vector<int> sub) {
        if(k == 0) {
            target.push_back(sub);
            return;
        }
        for(int i = f + 1; i <= n - k + 1 ; i++) {
            vector<int> temp = sub;
            temp.push_back(i);
            Combine(n, k - 1, i, target, temp);
        }
    }
};
//由于循环不知道循环次数 只能用递归