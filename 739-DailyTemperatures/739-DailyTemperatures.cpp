// Last updated: 2026/4/11 下午7:19:52
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
        stack<int> s;   
        vector<int> res(t.size());
        for(int i = 0; i < t.size(); i++)
        {
            while (!s.empty() && t[s.top()] < t[i])   // 遇到較高溫，stack空要跳過不然會報錯
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);  // stack 存入 index 而不是值
            
        }
        return res;
    }
};