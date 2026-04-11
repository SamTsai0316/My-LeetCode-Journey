// Last updated: 2026/4/11 下午7:19:37
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> candiesTF;
        int n = candies.size();
        int biggest=0;
        for(int i =0; i<n ; i++)
        {
            if(candies[i]>biggest)
            {
                biggest = candies[i];
            }
        }
        for(int j=0 ; j<n ; j++)
        {
            if(candies[j]+extraCandies<biggest)
            {
                candiesTF.push_back(false);
            }
            else
                candiesTF.push_back(true);


        }

        return candiesTF;
    }
};