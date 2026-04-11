// Last updated: 2026/4/11 下午7:20:15
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/*找出兩點 p q 最"近"的 ancestor (並不是數值最小)
1. 利用遞迴找出 p q 並返回該 root 放在 left right
2. 並且不是 p q 的點最終只會返回空
3. 遇到 left right 都非空的代表他會是最近的 ancestor
4. 最後再繼續返回，因為其他沒有 p q 的子樹只會返回空，所以我們設定 left right 有一個空的就返回非空的
如果兩個都空那也沒差 就返回空*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
            return root;
        return (left != NULL)? left : right;
    }
};