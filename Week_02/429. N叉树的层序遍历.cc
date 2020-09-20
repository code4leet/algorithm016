class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(root == nullptr) return {};
        queue<Node*> queNode;
        vector<vector<int>> vecRet;
        queNode.push(root);
        while(!queNode.empty())
        {
            vector<int> vecTmp;
            int nSize = queNode.size();
            for(int i=0;i<nSize; ++i)
            {
                Node* node = queNode.front();
                vecTmp.push_back(node->val);
                queNode.pop();
                for(auto& nodeTmp : node->children)
                {
                    queNode.push(nodeTmp);
                }
            }
            vecRet.push_back(vecTmp);
        }
        return vecRet;
    }
};