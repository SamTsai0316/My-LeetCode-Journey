// Last updated: 2026/4/11 下午7:19:34
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<pair<int, int>> s;
        vector<int> res(prices.size());
        s.push({0,prices[0]});
        
        for(int i = 1; i < prices.size(); i++)
        {
            while(!s.empty() && s.top().second >= prices[i])    // 找到折扣
            {
                res[s.top().first] = s.top().second - prices[i];
                s.pop();
            }
            
            s.push({i,prices[i]});
                
            
        }
        while(!s.empty())   // 無折扣的商品
        {
            res[s.top().first] = s.top().second;
            s.pop();
        }
        return res;
    }
};