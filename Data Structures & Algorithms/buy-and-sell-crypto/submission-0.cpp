class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int miniPrice=prices[0];
        int profit;
        for(int i=0;i<prices.size();i++){
            miniPrice=min(miniPrice,prices[i]);
            profit=prices[i]-miniPrice;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;

        
    }
};
