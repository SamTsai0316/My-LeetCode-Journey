// Last updated: 2026/4/11 下午7:19:38
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
class Solution {
public:
    /*ZigZag path 必須要左右交替走，用 bool 來左右交替走，決定 return 左或右的最大高度*/
    int result = 0;
    int dfs(TreeNode *root, bool isLeft)
    {
        if(!root)
            return 0;
        int l = dfs(root->left, true);
        int r = dfs(root->right, false);
        result = max(result,max(l,r));
        return (isLeft)? r+1 : l+1; // 因為必須左右交替，所以當isLeft為true時，代表上一個方向是左邊，那就得返回右邊高度
    }
    int longestZigZag(TreeNode* root) 
    {
       dfs(root, true);    // 起始是 true false 都沒關係，因為最後是 return result，重點是 l r 那邊要跟三目運算配合
       return result;  
    }

};