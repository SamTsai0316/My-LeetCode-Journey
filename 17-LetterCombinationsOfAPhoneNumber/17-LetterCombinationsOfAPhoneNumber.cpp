// Last updated: 2026/4/11 下午7:20:43
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if (digits.empty())
            return res;
        unordered_map<char, string> digitToLetters = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };  // unordered_map 是 hashtable, 這邊利用 char number 當作 index, 進而找出 value (abc...)
        letterCombine(digits, 0, "", res, digitToLetters);    // (input, index, 當前合成字串, res vector, hashtable)
        return res;
        

    }
    void letterCombine(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters)
    {
        if(idx == digits.length())  // idx 從0算，所以一樣代表字串都串完了
        {
            res.push_back(comb);    
            return;
        }
        string letters = digitToLetters.at(digits[idx]);    // 另 letters = 雜湊表中某一index的所有letters
        for (char curLetter : letters)  // 利用遞迴的方式使前面的 letter 跟後面的組成所有組合
        {
            letterCombine(digits, idx+1, comb + curLetter, res, digitToLetters );
        }

    };
};