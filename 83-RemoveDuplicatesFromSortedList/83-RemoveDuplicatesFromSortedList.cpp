// Last updated: 2026/4/11 下午7:20:32
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
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* prev = head;
        ListNode* newHead = head;
        if(head)
        {
            head = head->next;
            while(head)
            {
                if(prev->val == head ->val)
                {
                    prev->next = head->next;
                    head = head->next;
                }
                else
                {
                head = head->next;
                prev = prev->next;
                }
            }
        }
        
        return newHead;
    }
};