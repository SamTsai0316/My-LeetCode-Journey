// Last updated: 2026/4/11 下午7:20:20
class Solution {
public:

    bool isHappy(int n) 
    {
        unordered_set<int> usedNumber;
        while (usedNumber.find(n) == usedNumber.end())    // 因為 end 是最後一格的往後一格，表示沒找到，所以要繼續找，直到變成1或是找到已經出現過的數-> not a happy number
        {
            usedNumber.insert(n);
            n = getNextNumber(n);
            if(n == 1)
                return true;
        }
        return false;

    }
private:

    int getNextNumber(int n)
    {
        int res = 0;
        while (n > 0)
        {
            int digit = n % 10;
            res += digit * digit;
            n = n / 10; 
        }
        return res;
    }
};