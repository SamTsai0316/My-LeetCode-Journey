// Last updated: 2026/4/11 下午7:20:38
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        
        for(int i=0; i<haystack.length(); i++)
        {
            if (haystack.substr(i,needle.length()) == needle)
                return i;
            
        }       
        
        return -1;
        
    
    }
};