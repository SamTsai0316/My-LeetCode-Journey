// Last updated: 2026/4/11 下午7:19:20
class Solution 
{
public:
    long long totalCost(vector<int>& costs, int k, int candi) 
    {
        priority_queue<int, vector<int>, greater<int>> n1, n2;  // 將pq設成小到大
        int i = 0;
        int j = costs.size()-1;
        long long res = 0;
        int count = 1;
        while(count <= k)
        {
            while( n1.size() < candi && i<=j)n1.push(costs[i++]);
            while( n2.size() < candi && i<=j)n2.push(costs[j--]);   // i<=j 防止重疊又重複取
            int v1 = n1.empty()? INT_MAX : n1.top();
            int v2 = n2.empty()? INT_MAX : n2.top();    //如果重疊到導致 pq.top()是空會報錯

            if(v1 <= v2)
            {
                res += v1;
                n1.pop();
            }
            else
            {
                res += v2;
                n2.pop();
            }
            count++;
           
        }
        return res;



    }
};