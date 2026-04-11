// Last updated: 2026/4/11 下午7:21:14
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0, total = 0;
        ListNode* res = new ListNode();
        ListNode* temHead = res;    // 紀錄 new list 的頭部
        while(l1 || l2 || carry)    // 如果最後一個數有進位，那還要再加一的點，所以 carry 也要在條件式
        {
            total = carry;  // 當前點的值跟上一輪的進位一起算，進位不需要先加
            if(l1)
            {
                total += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                total += l2->val;
                l2 = l2->next;
            }
            carry = total/10;
            int num = total % 10;
            res->next = new ListNode(num);  
            res = res->next;
        }

        return temHead->next;
        
    }
};