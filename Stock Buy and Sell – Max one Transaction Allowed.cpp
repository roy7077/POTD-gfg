class Solution {
    public:
    int maximumProfit(vector<int> &prices) {
        int maxAns=0;
        int minPrice=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            maxAns=max(prices[i]-minPrice,maxAns);
            minPrice=min(prices[i],minPrice);
        }
        return maxAns;
    }
};
