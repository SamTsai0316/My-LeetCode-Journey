// Last updated: 2026/4/11 下午7:21:15
class Solution {
public:
    bool isPalindrome(int x) 
    {
        std::string str = std::to_string(x);
        int n = str.length();
        int j = n-1;
        for(int i=0; i<j; i++)
        {
            if(str[i]==str[j])
            {
                j--;
                continue;
            }
            else{
                return false;
                break;
            }
               
            
        }
       return true;
    }
};