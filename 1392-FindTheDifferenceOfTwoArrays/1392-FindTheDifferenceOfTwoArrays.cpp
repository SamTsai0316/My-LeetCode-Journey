// Last updated: 2026/4/11 下午7:19:39
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());

        vector<int> disvector1;
        vector<int> disvector2;

        for(int num:set1)
        {
            if(set2.count(num)==0)
                disvector1.push_back(num);
        }
        for(int num:set2)
        {
            if(set1.count(num)==0)
                disvector2.push_back(num);
        }
        return{disvector1,disvector2};

    }
};