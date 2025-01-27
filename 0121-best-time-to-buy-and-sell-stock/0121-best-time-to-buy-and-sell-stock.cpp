class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int i = 0;
        int max = 0;
        for (auto& price : prices) {
            int profit = price - min;
            if (max < profit)
                max = profit;
            if (min > price)
                min = price;
        }
        return max;
    }
};