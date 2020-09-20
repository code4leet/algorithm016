class Solution {
public:
    static bool cmp(pair<int,int>& m, pair<int, int>& n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        
        // hash累加次数
        unordered_map<int,int> hashMap;
        for(auto& num: nums)
        {
            hashMap[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp) > q(cmp); // 小顶堆
        for(auto& [num,count]:hashMap)
        {
            if(q.size() == k)
            {
                if(count>q.top().second)
                {
                    q.pop();
                    q.emplace(num,count);
                }
                continue;
            }
            q.emplace(num,count); //原位构造
        }
        vector<int> vecRet;
        while (!q.empty())
        {
            vecRet.emplace_back(q.top().first);
            q.pop();
        }
        
        return vecRet;
    }
};