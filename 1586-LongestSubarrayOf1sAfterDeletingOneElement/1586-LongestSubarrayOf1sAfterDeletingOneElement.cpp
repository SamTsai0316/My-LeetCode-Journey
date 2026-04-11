// Last updated: 2026/4/11 下午7:19:32
class Solution {
public:
    /*當遇到 0 的時候先紀錄當前的最大 count，然後新的 count 變成當前 0 之前最大的連續 1 數量，這樣始終都只會有一個 0 並且不用另外計被刪除的零的數量 */
    int longestSubarray(vector<int>& nums) 
    {
        int head = -1, tail = 0, currentCount = 0, prevCount = 0; // head 只是用來記錄當nums[tail]==0 時，在這個 0 之前最大連續 1 的數量
        // 當 vector 是 1 開頭的情況如果 head 為 0 會出錯，所以 -1
        while(tail < nums.size())
        {
            if(nums[tail] == 0)
            {
                prevCount = max(prevCount, currentCount);    // 先紀錄當前最大 subarray，
                currentCount = tail - head - 1;              // 新的 count 變成當前 0 之前最大的連續 1 數量，-1 所以當前 tail 的零不會算到
                head = tail;                                 // nums[head] 只會等於零，因為新的 count 已經包辦前面的 1，
                                                             // 所以這邊的 head 直接跳到 tail，給下一次頭尾都是零的時候用
            }
            else
                currentCount++;
            tail++;

        }
        prevCount = max(prevCount, currentCount);
        return currentCount == nums.size()? prevCount-1 : prevCount;  // if currentCount == n 代表全部都是 1

        

    }
};