// Last updated: 2026/4/11 下午7:19:53
class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        std::stack<int> stack;
        for(int i : asteroids)
        {
            if(i>0)
            {
                stack.push(i);
            }
            else // i<0
            {
                while(!stack.empty() && stack.top()>0 && -i>stack.top()) // i<0 !empty top正 -i>top
                {
                    stack.pop();
                }
                if(stack.empty()|| stack.top()<0)                        // i<0 and empty || i<0 top負
                {
                    stack.push(i);
                }
                else if( -i==stack.top() )                               // i<0 !empty -i==top
                    stack.pop();
            }                                          // i<0 !empty -i<top 如果i在while被撞掉 就直接掉過
        }

        std::vector<int> result(stack.size());
        int x=stack.size()-1;
        while(!stack.empty())
        {
            result[x--]=stack.top();
            stack.pop();
        }
        return result;
        

    }
};