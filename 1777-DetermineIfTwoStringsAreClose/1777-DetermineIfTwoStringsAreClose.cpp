// Last updated: 2026/4/11 下午7:19:31
class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        /*
        op1 op2 的先決條件必須要兩個字串不能沒有對方有出現的字母 並且所有字母頻率數要一樣才能在op2做交換
        */ 

        //1. 先用另外兩個陣列f1 f2 紀錄word1 word2 的a~z字母的出現次數
        vector<int> f1(26,0);
        vector<int> f2(26,0);

        for(char ch : word1)
        {
            f1[ch-'a']++; //ch-'a'==ch-97 e.g.ch=c, c-a=99-97=2
        }
        for(char ch : word2)
        {
            f2[ch-'a']++;
        }

        //2. 再透過比對f1f2同格是否都有出現 e.g. 不能word1有c 但word2沒有c (不同代表op1 op2做完後不會相等)
        for(int i=0; i<26; i++)
        {
            if(f1[i]==0&&f2[i]!=0 || f2[i]==0&&f1[i]!=0)
                return false;
        }

        //3. 在sort f1f2 然後依序比對不合就false (頻率都一樣才能換)
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0; i<26; i++)
        {
            if(f1[i]!=f2[i])
                return false;
            
        }
        return true;

        

    }
};