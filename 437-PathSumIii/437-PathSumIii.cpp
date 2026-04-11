// Last updated: 2026/4/11 下午7:20:03
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
    /*用遞迴跟 call dfs 的方式，對每一個點檢查她的所有 path 是否有符合 targetSum*/
    int ans = 0;
    void dfs (TreeNode* root, long long sum)  // 針對單一點對他的所有 path 做檢查，看有沒有符合 targetSum
    {                                         // 因為 sum 有可能負數扣到超過 int 32 bits 範圍，所以用 long long 64 bits
        if(!root)   // 遞回到空子點就退回       
            return; 
        if(root->val == sum)
            ans++;
        dfs(root->left, sum - root->val);    // 把當前root的值扣掉後看還缺多少再到剩下的 path 中找有沒有符合的，
        dfs(root->right, sum - root->val);   // 如果已經是0或負數那也會找不到 ans 也不會++
    }
    
    int pathSum(TreeNode* root, int targetSum) // dfs 是針對單一點對他的所有 path 做檢查，而主程式則是遞迴 root 到左右子
    {
        if(root)
        {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);    
        }
        return ans;
    }
    
};