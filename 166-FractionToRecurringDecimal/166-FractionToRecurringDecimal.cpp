// Last updated: 2026/4/11 下午7:20:23
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        string res = "";
        if (numerator == 0)
            return "0";
        if(numerator<0 ^ denominator<0) // 用xor決定要不要加負號
            res += "-";
        long long n = abs((long long) numerator);
        long long m = abs((long long) denominator); // 避免溢位

        res += to_string(n/m);  // 當除號的兩邊都是整數，那回傳只會有整數
        long long remainder = n % m;
        if(remainder == 0)
            return res;
        res += "."; // 有小數，所以加小數點

        unordered_map<long long, int> map;  // <當前餘數, 對應在 result 字串中的索引長度> (因為要塞入 "(" 所以紀錄 index)
        while(remainder != 0)
        {
            if(map.count(remainder))    // 餘數一樣代表有循環，如果有循環加入()
            {
                res.insert(map[remainder], "(");     // 把 "(" 塞到 map[remainder] 所記錄的索引的前面
                res += ")";
                break;
            }
            map[remainder] = res.size(); // 紀錄當前索引位置 
            remainder *= 10;
            res += to_string(remainder / m);
            remainder %= m; 
        }
        return res;

    }
};