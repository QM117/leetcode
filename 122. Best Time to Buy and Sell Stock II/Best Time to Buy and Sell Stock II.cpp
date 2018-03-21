class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
            return 0;
        int n = prices.size();
        int max = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1]) max += prices[i] - prices[i - 1];
        }
        return max;
    }
};
//that is a easy one, its for calculating the sum of the increment of two adjacent numbers. But at the first, i forgot the input conditions and want to use the if (prices[i] - prices[i - 1])... to substitute the if (prices[i] > prices[i - 1]), that means if (prices[i] - prices[i - 1] != 0)