// Last updated: 2026/4/11 下午7:19:27
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
    ListNode* deleteMiddle(ListNode* head) 
    {
        int i=1;
        ListNode* current = head->next;
        if(head==NULL|| head->next==NULL)  // 空linked list跟一個元素的最後都會返回 nullptr
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* one = head;
        ListNode* two = head;              // 創建三個指針 prev接著one(prev->next=one->next) one每次走一步 two兩步 

 /*當two(size偶數) or twonext(size奇數) 為空代表走到底 此時 one 剛好是  ⌊n / 2⌋th
   e.g. [2,3] [1,3,4] [2,3,4,5]*/ 
        while(two&&two->next)                                        
        {
            prev=one;
            one=one->next;
            two=two->next->next;
        } 

        if(prev) // 防止只有兩個元素的情況 prev有可能空(只要刪除one即可)
        {
            prev->next=one->next;
        }
        delete one; // free memory or 只有兩個元素時刪除第二個

        return head;
    }
};