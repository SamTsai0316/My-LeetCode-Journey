// Last updated: 2026/4/11 下午7:20:36
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<char> row[9]; // 每一列都是一個 set，可以記錄過出現的字符
        unordered_set<char> col[9];
        unordered_set<char> box[9]; // 將九宮格畫成九個箱子，
        for(int r = 0; r<9; r++)
        {
            for(int c = 0; c<9; c++)
            {
                if(board[r][c] == '.')
                    continue;
                
                char val = board[r][c];
                int boxNum = (r/3)*3 + (c/3);   // 算出是屬於哪一個箱子
                if(row[r].count(val) || col[c].count(val) || box[boxNum].count(val))    
                    return false; 
                row[r].insert(val);
                col[c].insert(val);
                box[boxNum].insert(val);

            }
        }
        return true;

    }
};