// Last updated: 2026/4/11 下午7:20:21
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
    /*使用 result.size() < level 來讓最右邊的 node 有資格存入 vector*/
    void bfs(TreeNode *root, int level, vector<int> &result)
    {
        if(root == NULL)
            return;
        if(root && result.size() < level)
            result.push_back(root->val);
        /*不能在這邊加 else return;，這會導致只要不符合 "root && result.size() < level" 那就不會在往下探訪會直接停住*/
        bfs(root->right, level+1, result);
        bfs(root->left, level+1, result);

    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        bfs(root, 1, result);
        return result;
    }
};