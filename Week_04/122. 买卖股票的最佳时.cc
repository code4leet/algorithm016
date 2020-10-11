class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int nAns = 0;
        int nSize = prices.size();
        for(int i=1;i<nSize;++i)
        {
            if(prices[i]>prices[i-1])
            {
                nAns += prices[i] - prices[i-1];
            }
        }
        return nAns;
    }
};