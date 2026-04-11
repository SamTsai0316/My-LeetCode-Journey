// Last updated: 2026/4/11 下午7:20:30
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
    int maxDepth(TreeNode* root) 
    {
        
        if(root==NULL)   //空BT
        {
            return 0;
        }
        else            //非空BT
        {
            int leftDepth = maxDepth(root -> left);     // 遞迴直到 left==NULL, 然後返回看左右誰大就+1
            int rightDepth = maxDepth(root -> right);
            return max(leftDepth,rightDepth)+1;
        }

    }
};