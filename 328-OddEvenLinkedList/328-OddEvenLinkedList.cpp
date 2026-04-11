// Last updated: 2026/4/11 下午7:20:12
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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) // 先確認head非空再宣告 不然會有問題
            return head;
        ListNode* even=head->next;
        ListNode* odd=head;
        ListNode* evenhead=even;

        
        while(even&&even->next)       // 用略過even的方式先將odd跟even兩個list分開最後在連上evenhead  
        {
            odd->next=even->next;    // 將原本的oddnext略過even，odd要先做因為條件式是放even
            odd=odd->next;
            even->next=even->next->next; // 將下一個even先連上 等下一次odd->next=even->next;會使odd斷開
            even=even->next;

        }
        /*even&&even->next 當違反 前者做26行時會跳出 後者做25行時會跳出
          而odd始終都會停在odd最後一個，因為even->next為空時23行不會再做到*/
        odd->next=evenhead;
        return head;
    }
};