// Last updated: 2026/4/11 下午7:19:33
class Solution {
public:
    /*
      1. 用 adj back 兩個 vector<vector<int>> 紀錄正常方向跟反方向的兩種圖
        e.g. 原本的 connections 會記錄 { {0,1},{0,2},{3,0} } 而 adj[0] 就會放 0 可以直接到的點1,2
         1. 在 adj 中碰到灰點(尚未被探訪的點)那就是代表要改變方向的邊 +1
         2. 而 back 則是找出在正向圖用 BFS 探訪不到的點 然後再透過這些點的 adj 找出灰點
      2. 建立 queue 實作 BFS，建立一維 vector 紀錄 n 個點是否被探訪 */
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n),back(n);
        vector<int> visited(n);
        queue<int> q;
        int ans = 0;
        q.push(0);
        for(vector<int> c : connections)    // 建立正向圖跟反向圖
        {
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            for(int a : adj[curr])
            {
                if(!visited[a])
                {
                    ans++;
                    q.push(a);
                   
                }
            }
            for(int b : back[curr])
            {
                if(!visited[b])
                    q.push(b);
            }
        }
        return ans;
    }
};