// Last updated: 2026/4/11 下午7:19:40
class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        // 1. 先 sort arr 然後用 while loop 計算同樣的數字出現次數 並將出現次數打入 new vector v
        
        int n = arr.size();
        int i=0;
        sort(arr.begin(),arr.end());
        vector<int> v;
        do
        {
            int cnt=1;
            while(i+1<n && arr[i]==arr[i+1]) //[1,1,2]
            {
                cnt++;
                i++;
            }
            v.push_back(cnt);
            i++;
            
        }while(i<n);

        sort(v.begin(),v.end());

        for(int m=1 ; m<v.size() ; m++)
        {
            if(v[m]==v[m-1])
                return false;
            
        }
        return true;



        // 2. 因為相同的數字只會計算一次 所以v不能有相同的數字 如果有就 false

        
    }
};