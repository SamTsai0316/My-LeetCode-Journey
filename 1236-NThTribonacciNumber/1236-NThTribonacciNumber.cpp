// Last updated: 2026/4/11 下午7:19:41
class Solution 
{
public:
    int tribonacci(int n) 
    {
        int a = 0;
        int b = 1;
        int c = 1;
        int d;
        int count = 2;
        if(n < 3)
            return (n < 1)? 0 : 1;
        while(count<n)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
            count++;
        }
        return c;
    }
};
/*
遞迴版本 但太花時間

public:
    int tribonacci(int n) 
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        return (tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3) );
    }
};





*/