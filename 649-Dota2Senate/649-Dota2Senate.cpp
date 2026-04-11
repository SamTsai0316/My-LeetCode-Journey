// Last updated: 2026/4/11 下午7:19:55
class Solution {
public:
    /*想法 : 用兩個 queue 跟 Index 來記錄兩方的位置順序，比大小，比完兩邊都要刪掉，然後比較小的在後面新增新的 Index 繼續下一輪比較，直到某一方先為空那就是另一方獲勝

        1. 用當前 Index 存入 R or D 陣營的 queue
        2. 依序比較兩個 queue 看誰的 Index 比較後面就 push(n++)
        (假設 R 把 D BAN 掉，但 R 還在，只是要等下一輪，所以依序放入 Index n 後面的數字，接著放入 queue，之後還得繼續比大小，直到某一方為空)
        3. 然後兩邊都 pop (把第一個刪掉)
        4. 持續 2~3 直到某一個先空*/
        
    string predictPartyVictory(string senate) 
    {
        queue<int> rad, dir;
        int n = senate.length();
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
                rad.push(i);
            else
                dir.push(i);    
        }
        while(!rad.empty() && !dir.empty())
        {
            if(rad.front() < dir.front())
                rad.push(n++);
            else
                dir.push(n++);
            rad.pop();
            dir.pop();
        }
        return rad.empty()? "Dire" : "Radiant";




    }
};