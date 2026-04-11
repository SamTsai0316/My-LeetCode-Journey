// Last updated: 2026/4/11 下午7:20:35
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string ,vector<string>> ans;
        for(string s : strs)    // 外圈檢查每一個 string
        {
            array<int, 26> count = {0}; // 建立array且內容是int，有26格，每一格皆為0
            for(char c : s) // 內圈加總各個string的字符
            {
                count[c-'a']++; // 透過 ASCII -'a' 紀錄出現過的字母
            }
            string key; // 因為後去用 res[key]，所以 key 得用 string
            for(int num : count)    // num 表示 count 每一格中的數字
            {
                key += to_string(num) + '#';
                // 因為 key 用 string， 所以用to_string 將 int 轉成字符，有一樣字母的字串的 key 值相同
            }
            ans[key].push_back(s);
            
        }
        vector<vector<string>> res;
        for(auto& t : ans)  // t會長成 ans 每一格的樣子 e.g. {1#0#0#...#0, ["ate","eat"]}
        {
            res.push_back(move(t.second));  // move 是將存放的容器的地址改成 res，不用的話就是一個個複製過去
        }
        return res;
    }
};