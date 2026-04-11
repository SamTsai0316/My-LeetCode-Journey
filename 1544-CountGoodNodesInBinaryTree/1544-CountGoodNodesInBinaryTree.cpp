// Last updated: 2026/4/11 下午7:19:36
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
   
    /*1. 因為需要一個額外的數值紀錄path中最大值的數 所以另外開一個method原本的goodNodes只需要call metohd and return final value
      2. good則是一開始先記錄path上最大值，然後遞迴左右子樹 最後檢查root是否有比maxNode大，有就是good 所以返回值的i++*/
    int good(TreeNode* root , int maxNode)
    {
        if(root)
        {
            int i = good(root->left,max(root->val,maxNode) )+good(root->right,max(root->val,maxNode) );
            if (root->val>=maxNode)
                i++;
            return i;
        }
        return 0;
    }
    int goodNodes(TreeNode* root) 
    {
        return good(root,-10001);   
        //為了確保一開始maxNodes一定要吃到非空node->val 所以設定比題目給的value還要小(Each node's value is between [-10^4, 10^4]).
       
        
    }
    
};