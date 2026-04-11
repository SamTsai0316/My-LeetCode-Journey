// Last updated: 2026/4/11 下午7:19:48
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
    /*每次用 dfs 裡的 while loop 找到 leaf 才返回值*/
    int dfs(stack<TreeNode*> &s)    // & 是為了直接修改 s1 s2 的值，沒有的話會直接複製一份新的 stack    
    {
        while(true)
        {
            TreeNode *node = s.top();
            s.pop();
            // 因為LIFO, 所以先右再左會在找到最左邊 leaf 後，stack top 會是上一個有右子的 parent，然後她會再 push 他的右子...找到第二個 leaf
            if(node->right)      
                s.push(node->right);
            if(node->left)                    
                s.push(node->left);
            if(!node->left && !node->right)   // when node is leaf then return leaf's value
                return node->val;       
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        stack<TreeNode*> s1, s2;    // stack 裡面存放的格式是 TreeNode 的指針，所以後面設定的 node 才可以保留格式繼續用 left right
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty())   // 找到最後一個 leaf 的時候 stack 就會空，所以不會執行下一輪
        {
            if(dfs(s1) != dfs(s2))
                return false;
        }
        return s1.empty() && s2.empty();    // 跳出 while 的條件式只要有一個 stack 空了就會跳，所以只要兩邊都是空那就代表 leaf 都一樣
    }
};