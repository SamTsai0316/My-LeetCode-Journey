// Last updated: 2026/4/11 下午7:19:57
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c = flowerbed.size();
        int count=0;
        for(int i=0 ; i<c ; i++)
        {
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==c-1 || flowerbed[i+1]==0) )
            {
                flowerbed[i]=1;
                count++;

            }
        }
        
        if(count<n)
            return false;
        else
            return true;
    }
};