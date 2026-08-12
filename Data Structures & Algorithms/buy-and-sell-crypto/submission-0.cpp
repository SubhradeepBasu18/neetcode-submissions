class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost = prices[0], maxProfit = 0;
        
        for(int price: prices){
            minCost = min(minCost, price);
            maxProfit = max(maxProfit, price-minCost);
        }
        return maxProfit;
    }
};
