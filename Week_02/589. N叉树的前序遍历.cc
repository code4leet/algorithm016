class Solution {
public:
    vector<int> vecRet_;
    vector<int> preorder(Node* root) 
    {
        if(root == nullptr) return vecRet_; // 退出条件
        vecRet_.push_back(root->val); // 当前节点处理
        for(auto& node : root->children)
        {
            preorder(node);
        }
        return vecRet_;
    }
};