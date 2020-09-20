class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> vecRet;
        unordered_map<string,vector<string>> mapVec;
        for(auto& str : strs)
        {
            auto strTmp = str;
            sort(strTmp.begin(),strTmp.end());
            mapVec[strTmp].push_back(str);
        }
        for(auto& [strTmp, vec] : mapVec)
        {
            vecRet.push_back(vec);
        }
        return vecRet;
    }
};