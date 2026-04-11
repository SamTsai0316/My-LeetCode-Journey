// Last updated: 2026/4/11 下午7:19:47
class Solution {
public:
    
    
    bool canEatInTime(vector<int>& piles, int mid, int h)
    {
        double count = 0;
        for(int pile : piles)
        {
            int div = pile / mid;
            count += div;
            if(pile % mid != 0) count++;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        sort(piles.begin(), piles.end());
        int n = piles[piles.size()-1];
        int left = 1, right = n;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(canEatInTime(piles, mid, h))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }


    
            
};

