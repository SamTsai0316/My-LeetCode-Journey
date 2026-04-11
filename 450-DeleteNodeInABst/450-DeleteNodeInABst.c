// Last updated: 2026/4/11 下午7:20:01
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) 
{
    if(root)
    {
        if (key<root->val)
            root->left = deleteNode(root->left,key);    // 這裡不用 return 因為目標是遞迴找出key刪除後，再接上，直接 return 會回傳不完整的樹
        else if(key>root->val)
            root->right = deleteNode(root->right,key);

        /*刪除點a幾種情況
        1. a沒有子點 直接回傳空
        2. a 有左子無右子
        3. a 有右子無左子
        4. a 有兩子
        */
        else // key == root->val
        {
            if(!root->right && !root->left)
                return NULL;
            if (!root->right || !root->left)
                return root->left?root->left:root->right;
            // 找出左子樹最大 or 找出右子樹最大
            struct TreeNode *temp = root->left;
            while(temp->right!=NULL)
                temp = temp->right;
            root->val = temp->val;
            root->left = deleteNode(root->left,temp->val);   
        }

    }
    return root;
    

}