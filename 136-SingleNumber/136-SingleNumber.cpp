// Last updated: 2026/4/11 下午7:20:27
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        std::stack<int> s;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size() ; i++)
        {
            if(s.empty() || s.top()==nums[i] )
            {
                s.push(nums[i]);
            }
            else // s非空 and top!=num[i]
            {
                if(s.size()>1)
                {
                    while(!s.empty())
                        s.pop();
                    s.push(nums[i]);
                }
                else
                {
                    return s.top();
                }
            }
        }
        return s.top();

    }
};