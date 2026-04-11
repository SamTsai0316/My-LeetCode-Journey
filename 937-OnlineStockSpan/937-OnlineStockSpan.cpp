// Last updated: 2026/4/11 下午7:19:46
class StockSpanner 
{
private:
    stack<pair<int,int>> s; 
public:
    StockSpanner() {}
    
    int next(int price) // 每一次報價就回傳
    {
        int span = 1;
        while(!s.empty() && s.top().first <= price)  //非空且 top比當前價格小 
        {
            span += s.top().second;
            s.pop();    // 更新 span 後把原本比自己小的都踢掉。e.g. 1234，當輪到4時，stack 裡面只剩{3,3}，因為存2踢1 存3踢2
        }
        s.push({price,span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */