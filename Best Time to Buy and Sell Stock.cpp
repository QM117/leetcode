class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j <= prices.size() - 1; j++)
            {
                if (prices[j] - prices[i] > max_profit) max_profit = prices[j] - prices[i];
            }
        }
        return max_profit;
    }
};
