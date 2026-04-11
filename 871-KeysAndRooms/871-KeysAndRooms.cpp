// Last updated: 2026/4/11 下午7:19:49
class Solution {
public:
    
    /*題意是只要你有鑰匙就可以打開房間，沒有先後順序*/
    
    void dfs(int currentNo, vector<vector<int>> &rooms, vector<bool> &canVisit)    // 用 & 可以直接改動 vector 裡的參數，並且效率比較好，因為如果不用是複製整個 vector 進來
    {                                                                              // 用 DFS 把有鑰匙的數字用 vector<bool> 紀錄
        canVisit[currentNo] = true;
        for(int i : rooms[currentNo]) // 依序檢查該房間的鑰匙集合，確認是否依經有，如果沒有就用 dfs 打開然後再遞迴探訪新的打開的房間內的鑰匙
        {
            if(!canVisit[i])
                dfs(i, rooms, canVisit);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool> canVisit(rooms.size(),0); // 從零號房間有的鑰匙延伸出去，紀錄所有能打開的房間以及該房間的鑰匙.....
        dfs(0, rooms, canVisit);   


        for(int i : canVisit)    // 最後檢查 keyVector 是否每個都是 true
        {
            if(!i)
                return false;
        }
        return true;
    }
};