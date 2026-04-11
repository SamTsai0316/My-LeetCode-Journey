// Last updated: 2026/4/11 下午7:20:26
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    /*用快慢雙指針，看是先只到 false 還是先兩個指針一樣(有cycle)*/
public:
    bool hasCycle(ListNode *head) 
    {
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast && fast->next)   // 不用比 value，比較位置即可
            {
                fast = fast->next->next;
                slow = slow->next;
                
                
                if(fast == slow)
                    return true;
            }
            return false;

    }
};