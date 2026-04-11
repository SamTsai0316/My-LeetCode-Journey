// Last updated: 2026/4/11 下午7:19:24
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> p;
        for(int i = 0 ; i<nums1.size() ; i++ )   
        {
            p.push_back({nums2[i], nums1[i]});  // 要加上{}，因為push_back正常只能加一物
        }
        
        sort(p.rbegin(),p.rend());
        long long sum = 0;
        long long ans = 0;
        priority_queue<int> pq; // 大到小排列
        for(int i = 0 ; i<k-1 ; i++ )   
        {
            sum += p[i].second;
            pq.push(-p[i].second);    // 用負的才能把最小的放在 top
        }
        for(int i = k-1 ; i<nums1.size() ; i++ )    // 利用 pq 維持sum 為長度 k-1 之最大和
        {
            sum += p[i].second;
            pq.push(-p[i].second);
            ans = max(ans, sum * p[i].first);    
            sum += pq.top();    
            pq.pop();   // 每次 pq 自己剔除最小的
        }
        return ans;


    }
};
/* 因為已經把 nums2 由大到小排序，所以先取 k-1 個後，之後取的第 k 個的 nums2 必是最小。
   而每次 pq 會把最小的 nums1 給剔除 (因為前k-1個nums2不會用所以不影響) */
// pq 都儲存負值的 nums1， 所以 pq.top() 會是最小值，每次剔除最小值