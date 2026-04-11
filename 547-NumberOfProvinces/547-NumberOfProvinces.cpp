// Last updated: 2026/4/11 下午7:19:59
class Solution 
{
public:
    /*
    
    函式:
        *union : 用於將不同 group 但相連的點連接，也就是把其中一個群組的老大的 v[i] 放入另一個 group 的老大號碼
        *parent : 定義每一個 group 中的老大，並且非老大會員的 v[i] 都是放老大 index，而老大維持 -1 以計算最後有幾個 group

    1. 建立一個一維的 vector 用於紀錄 n 個點有幾個 group (起始為 -1)
    2. Matrix 由左到右、上到下 發現有 1 的格子就對該兩點 i j 做 union
    3. 確認兩點的 parent 是否一樣，一樣就返回，不一樣就要將其中一個的老大格子改成另一群組的老大 index
    4. 最後計算 vector 中有幾個 -1 而得到幾個 group
     */
    vector<int> v;  // 建立在外面 就不用每一個函式都要 tag 
    int parent(int i)
    {
        if(v[i] == -1)
            return i;
        return v[i] = parent(v[i]); // 因為有可能原本的老大不再是老大，會造成已經在同一個群組的點重複 union，所以每次檢查都是遞迴找到真正的老大
    }
    void Union(int a, int b)
    {
        int pa = parent(a);
        int pb = parent(b);
        if(pa == pb)    // 3.
            return;
        v[pa] = pb;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        v = vector<int>(n, -1); // 1.
        for(int i = 0; i < n; i++)  // 2.
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j])
                    Union(i,j);
            }
        
        int c = 0;
        for(int k = 0; k < n; k++)
        {
            if(v[k] == -1)
                c++;
        }
        return c;
    }
};