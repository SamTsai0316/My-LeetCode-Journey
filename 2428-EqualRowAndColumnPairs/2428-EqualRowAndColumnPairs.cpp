// Last updated: 2026/4/11 下午7:19:21
class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        /*利用 map<vector<int>, int> mp 來記錄每一列出現的次數 (vector<int>是key也就是紀錄的，int則是value用來計算出現的次數)
        然後將每一行裝入一維的 vector v ，再用 mp[v] 檢查該 column 出現過的次數，並算到 output*/
        int count = 0; 
        map<vector<int>, int> mapEachRow;

        for(int i = 0; i < grid.size(); i++)    // 紀錄 grid 每一 row 出現的次數
        {
            mapEachRow[grid[i]]++;
        }
        for(int i = 0; i < grid[0].size(); i++ )    // 將 columns 每一個元素記錄到新的一維 vector
        {
            vector<int> colVector;
            for(int  j = 0; j < grid.size(); j++)    
                colVector.push_back(grid[j][i]);
            count += mapEachRow[colVector];         // 比對該 column 有沒有在之前的 row 出現過
        }
        return count;






    }
};