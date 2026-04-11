// Last updated: 2026/4/11 下午7:20:05
class Solution 
{
public:

    string decodeString(string s) 
    {
        /*以一組[]為一輪，如果是[ [] ] 內嵌的也是會把裡面的處理好 跟著外面的一起push k 次*/
        /*
        1. push直到遇到']'，所以stack會有在遇見']'以前所有的字串(數字or字母or'[')
        2. pop 字符到新的字串 直到遇見 '['
        3. pop '['
        4. 用 stoi() 紀錄'['之後遇到的數字 (有可能數字是十位數百位數...所以用while)
        5. 假設k次，那將新字串 push k 次到原本的stack
        6. 結束一輪 繼續下一輪[]
        */
        string string1;
        stack<char> st;
        
        string result = "";
        int n = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=']')   // push直到遇到']'，所以stack會有在遇見']'以前所有的字串(數字or字母or'[')
            {
                st.push(s[i]);
            }
            else    // 遇上']'要pop到新字串
            {
                string tem = "";    // 儲存當前']'之前的字串 所以每次要更新
                string count = "";  // 儲存當前'['前面的數
                while(st.top() != '[') // 第一次top一定是字母，遇到數字前會先遇到'['
                {
                    tem = st.top() + tem;
                    st.pop();
                }
                st.pop();   // 遇上'['直接pop
                while(!st.empty() && isdigit(st.top())) // 有可能數字是十位數百位數...所以用while，有可能已經是空導致isdigit讀不出來 所以empty要放前面
                {
                    count = st.top() + count;
                    st.pop();
                }
                int kTimes = stoi(count);   // 運用 soit 將字串轉換成 int
                while(kTimes--)
                {
                    for(int s=0; s<tem.length(); s++)
                        st.push(tem[s]);    // 一輪[]內的數push k time 到 st，所以在for loop結束前st會有完整所有次數的字串    
                        //以"3[a2[c]]"為例子，cc push到原本的stack 所以變成 top -> c c a  ，然後之後會一起push三次
                    
                }
            }
           
        }
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;

    }
};