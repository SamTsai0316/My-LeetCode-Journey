// Last updated: 2026/4/11 下午7:19:45
class RecentCounter {
private:
    
    
        std::vector<int> records;
        int start=0;
    
public:
    /*題目是說input:RecentCounter ping 是呼叫函數，所以第一次都會執行RecentCounter()並做初始化start跟建立vector
      之後的ping(t)就會依序填入vector 然後再比對後回傳範圍內的calls數量 */
    
    RecentCounter():start(0){};
    int ping(int t) 
    {
        
        
        records.push_back(t);               // 因為t是遞增的，所以依序放入即可
        while(records[start]<t-3000)        // 只要record[start]沒有小於t-3000 代表該格子中的值有在範圍內
        {
            start++;
        }
        return records.size()-start;        // 因為start指向範圍內第一個call，所以用全部vector的大小-start 即可得到範圍內的call數量
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */