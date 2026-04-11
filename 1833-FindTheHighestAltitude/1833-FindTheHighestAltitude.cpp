// Last updated: 2026/4/11 下午7:19:29
class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size();
        int highest=0;
        int result=0;
        for(int i=0 ; i<n ; i++)
        {
            result+=gain[i];
            if (result>highest)
                highest = result;
        }
        return highest;
    }   
};