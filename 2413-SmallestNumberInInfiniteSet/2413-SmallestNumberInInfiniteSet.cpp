// Last updated: 2026/4/11 下午7:19:22
class SmallestInfiniteSet {
public:

    int cur;    // cur 紀錄無限序列當前最小
    set<int> s; // 用來暫存 addback 的數值 (原無限序列不影響)
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        if(s.size()){
            int res = *s.begin();
            s.erase(res);
            return res;
        }
        else{   // 如果s空，代表刪無限序列的最小數字
            cur++;
            return cur-1;
        }
    }
    
    void addBack(int num) {
        if (num < cur)
            s.insert(num);
    }   // 用 cur 紀錄當前最小，所以只要 num > cur 代表數字還在裡面
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */