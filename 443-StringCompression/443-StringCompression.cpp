// Last updated: 2026/4/11 下午7:20:02
class Solution {
public:
    /**/
    int compress(vector<char>& chars) 
    {
        int ans = 0;    // 用額外的變數紀錄當前更新的位置，就不用 resize 
        for(int i = 0; i < chars.size();)
        {
            char currentLetter = chars[i];  
            int count = 0;  // 計算重複次數           
            while(i < chars.size() && chars[i] == currentLetter)   // 先找出第一個不符的
            {
                i++;        // 紀錄當前位置 
                count++;    
            }
            chars[ans++] = currentLetter;    // 先放入當前的字母，再放入次數

            if(count > 1)   // 一次的不用放入 1 所以直接跳過
            {
                for(char c : to_string(count))
                {
                    chars[ans++] = c;
                }
            }
          
           
        }
        return ans;
    }
};