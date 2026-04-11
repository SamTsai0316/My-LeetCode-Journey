// Last updated: 2026/4/11 下午7:20:18
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    

    struct ListNode *nextN =NULL;
    struct ListNode *current =head;
    struct ListNode *prevN =NULL;

    while(current)
    {
        nextN=current->next;
        current->next=prevN;
        prevN = current;
        current = nextN;
        
    }
    
    return prevN;
}