class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ll = s.size();
        int dict = wordDict.size();
        vector<bool> dp(ll+1,false);
        dp[0] = true;
        for(int i ;i < ll+1 ; i++){
            for(int j = 0;j<dict;j++){
                if(dp[i]){
                    string str = s.substr(i,wordDict[j].size());
                    if(str == wordDict[j]){
                        dp[i+wordDict[j].size()] = true;
                    }
                }
            }
        }
        for(int k = 0; k < s.size() + 1; k++) cout<<dp[k];
        return dp[ll];
    }
};
//别人的方法 但感觉不需要用动态规划做 或许我没理解题目意思