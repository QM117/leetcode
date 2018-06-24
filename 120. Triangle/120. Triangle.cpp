class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int dp[triangle.size()][triangle.size()] = {0};
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
                else if(j == i) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else dp[i][j] = min(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
            }
        }
        int minimum = dp[triangle.size() - 1][0];
        for(int k = 1; k < triangle.size(); k++)
            if(minimum > dp[triangle.size() - 1][k]) minimum = dp[triangle.size() - 1][k];
        return minimum;
    }
};
//最基础的动态规划 很好的说明了动态规划的思路