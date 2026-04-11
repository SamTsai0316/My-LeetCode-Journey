// Last updated: 2026/4/11 下午7:19:42
class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        return (str1+str2==str2+str1)?(str1.substr(str1.length()-gcd(str1.length(),str2.length()),str2.length())):("");
    }
};

/*
1. 運用三目運算 ()?():() ，條件式兩字串前後交換相加必須相等 -> 代表str1可以由str2組成
2. 所以如果不成立返回空字串，如果成立就去計算兩個字串長度的最大公因數->代表str1可以由最大這個長度的str2組成
3. substr(起始位置,長度) 起始位置用str1去算，長度用str2，因為長度最多就str2.length(超過不會算到)
substr超過不會算到e.g.Input: str1 = "ABABAB", str2 = "ABAB" Output: "AB"



*/