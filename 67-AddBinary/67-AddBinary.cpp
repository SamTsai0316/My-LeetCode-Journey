// Last updated: 2026/4/11 下午7:20:33
class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int n = a.length()-1;
        int m = b.length()-1;
        string s;
        int carry = 0;
        while( m >= 0 || n >= 0 || carry )
        {
            int curNum = carry;
            if(n >= 0)
                curNum += a[n--]-'0';
            if(m >= 0)
                curNum += b[m--]-'0';
            if (curNum > 1)
            {
                carry = 1;
                curNum -= 2;
            }
            else
                carry = 0;
            
            s.insert(s.begin(), curNum + '0');
        }
        return s;
    }
};