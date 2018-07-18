class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 0; i < n; i++) {
            int bit = 1<<i;
            for(int j = res.size() - 1; j >= 0; j--)
                res.push_back(bit | res[j]);
        }
        return res;
    }
};
//这方法很奇妙 利用了每次变化与之前的规律来做 但我不清楚这是不是动态规划