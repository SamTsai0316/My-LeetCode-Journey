// Last updated: 2026/4/11 下午7:20:09
class Solution {
public:
    string reverseVowels(string s) 
    {
        std::vector<char> dq;
        

        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'|| s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                dq.push_back(s[i]);
                
            }
        }
        int j=dq.size()-1;
        for(int c=0 ; c<s.length() ; c++)
        {
            if(s[c]=='a'||s[c]=='e'||s[c]=='i'||s[c]=='o'||s[c]=='u'|| s[c]=='A'||s[c]=='E'||s[c]=='I'||s[c]=='O'||s[c]=='U')
            {
                s[c] = dq[j];
                j--;
            }
        }
        return s;
    }

};