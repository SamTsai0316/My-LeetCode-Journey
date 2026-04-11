// Last updated: 2026/4/11 下午7:20:45
class Solution 
{
public:
    // num 只會到3999 所以用hash table 將nu分成千百個位數 把各個1-9都列出來
    static constexpr string R[4][10]
    {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
        {"", "M", "MM", "MMM","","","","","",""}
    };
    string intToRoman(int num) 
    {
        return R[3][num/1000]+R[2][num/100%10]+R[1][num/10%10]+R[0][num%10];
            

    }
};