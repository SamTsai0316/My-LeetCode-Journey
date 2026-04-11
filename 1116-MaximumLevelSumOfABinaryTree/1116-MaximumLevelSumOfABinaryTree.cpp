// Last updated: 2026/4/11 下午7:19:43
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
    void bfs(TreeNode *root, int level, vector<int> &result)
    {

        if(root==NULL)
            return;
        if(level < result.size() )
            result[level] += root->val;
        else
            result.push_back(root->val);
        bfs(root->left, level+1, result);
        bfs(root->right, level+1, result);

    }
    
    
    int maxLevelSum(TreeNode* root) 
    {
        int maxNo = INT_MIN;
        int maxLevel = 0;
        vector<int> result;
        bfs(root, 0, result);
        for(int i = 0; i < result.size(); i++)
        {
            if(result[i] > maxNo)
            {
                maxNo = result[i];
                maxLevel = i+1;
            }    
        }
        return maxLevel;
    }
};