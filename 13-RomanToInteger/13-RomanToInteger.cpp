// Last updated: 2026/4/11 下午7:20:45
class Solution {
public:
    
    int romanNum(char a)
    {
       switch(a)
       {
            case 'I' : 
                return 1;
            case 'V' : 
                return 5;
            case 'X' : 
                return 10;
            case 'L' : 
                return 50;
            case 'C' : 
                return 100;
            case 'D' : 
                return 500;
            case 'M' : 
                return 1000;
            default :
                 return 0;

       } 
      
    }   
    int romanToInt(string s)
    {
        int n = s.length();
        int result = 0 ;
        for (int i = 0; i<n ; i++)
        {
            
            if (i< n-1 && romanNum(s[i]) < romanNum(s[i+1]) )
            {
                result -= romanNum(s[i]);
            }
            else
            {
                result += romanNum(s[i]);
            }
        }
    
        return result;
    }
        


    

};