// Last updated: 2026/4/11 下午7:20:04
class Solution 
{
   /*用圖解的方法 a/b 代表 a 走到 b ， a/b=2、b/c=3 所以 a/c=6*/ 
public:
    unordered_map<string, vector<pair<string, double >>> adjList;
    unordered_map<string, bool> visited;
    double querAns;
    /*利用 adjList 建立圖表，記錄每一個點的相鄰點跟邊權重 e.g. adjList[a] = {{b,1}, {c,2}}
      利用 visited 避免遞迴 dfs 的時候無限迴圈探訪已經被找過的點*/

    bool dfs(string startNode, string endNode, double productOfPath)
    {
        /*先檢查 querues 裡面的點有沒有存在 adjList，如果不存在就會等於 adjList.end()，
        adjList.end() 是什麼? end() 是 C++ unordered_map 的一個成員函式。
        它回傳的是 一個特殊的 iterator，表示「超出 map 最後一個元素的位置」。
        不表示一個有效的 key，它是一個「終點指標」。*/
        if(adjList.find(startNode) == adjList.end() || adjList.find(endNode) == adjList.end())
            return false;
        if(startNode == endNode && adjList.find(startNode) != adjList.end())
        {
            querAns = productOfPath;
            return true;
        }

        bool isPath = false;
        visited[startNode] = true;
        for (int i = 0; i < adjList[startNode].size(); i++)
        {
            if(!visited[adjList[startNode][i].first])  // 尋找 startNode 還沒被探訪過的鄰點
            {
                isPath = dfs(adjList[startNode][i].first, endNode, productOfPath * adjList[startNode][i].second);
                if(isPath)
                    break;
            }
        }
        visited[startNode] = false; // 復原 visited 狀態，提供 querise 的下一組合用 
        return isPath;

    }    

    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        for(int i = 0; i < n; i++)  // 用 adjList 建立 equation 圖
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]}); // 正反向的路徑都要記錄
            visited[equations[i][0]]= false;
            visited[equations[i][1]] = false; // 把登記過的點也登錄在 visited 的 unorederd map
        }
        
        for(int i = 0; i < m; i++)
        {
            querAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);
            if (pathFound)
                ans[i] = querAns;
            else
                ans[i] = -1;
        }
        return ans;
    }
};


