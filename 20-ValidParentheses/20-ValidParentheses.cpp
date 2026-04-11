// Last updated: 2026/4/11 下午7:20:41
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        std::stack<char> st;
        if (n==0)
            return false;
        for (int i=0 ; i<n ; i++)
        {
            char ch = s[i];
            
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;
                else
                {
                    char top = st.top();
                    if( (ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{') )
                    {
                        st.pop();
                    }
                    else
                    return false;

                }
            }
        }
        if (st.empty())
            return true;
        else 
            return false;
        
    }
};