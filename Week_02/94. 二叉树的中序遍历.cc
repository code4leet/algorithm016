class Solution {
public:
    vector<int> vecRet_;
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return vecRet_;
        }
        inorderTraversal(root->left);
        vecRet_.push_back(root->val);
        inorderTraversal(root->right);
        return vecRet_;
    }
};