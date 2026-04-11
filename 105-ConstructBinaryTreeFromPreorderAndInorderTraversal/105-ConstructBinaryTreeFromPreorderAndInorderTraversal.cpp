// Last updated: 2026/4/11 下午7:20:29
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return build(preorderQueue, inorder);
    }
private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder)
    {
        if(!inorder.empty())    // 用 inorder 比較準確
        {
            int val = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);    // it 是地址，所以用 auto
            int idx = it - inorder.begin();
            /*找出第一個 preorder(當前root) 在 inorder 中的位置與距離*/

            TreeNode* root = new TreeNode(val); // *表示指向節點的地址，因為等等要用 root->left... 所以這裡用地址表示
            vector<int> leftinorder (inorder.begin(), inorder.begin()+idx);
            vector<int> rightinorder (inorder.begin()+idx+1, inorder.end());
            root->left = build(preorder, leftinorder);
            root->right = build(preorder, rightinorder);
            /*遞迴找出所有點*/
            return root;
        }
        return nullptr;
    }


};