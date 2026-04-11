// Last updated: 2026/4/11 下午7:20:10
class Solution {
public:
    vector<int> countBits(int n) 
    {
        std::vector<int> result;
        for(int i=0 ; i<=n ; i++)
        {
            bitset<32> b(i);
            
            result.push_back(b.count());
        }
        return result;
        

    }
};
/*
1. 利用 bitset<多少bit> b(要轉的數); 將value轉成二進制
2. 然後依序將各個value的1數量用count紀錄，二進制的數值接用count()會output 1 的數量
3. 正常字串用 count(起點,終點,要找的值)




*/