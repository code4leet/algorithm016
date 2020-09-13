class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> retVec;
        unordered_map<int,int> mapRecord; // num,index
        for (int i = 0; i<nums.size();++i)
        {
            if(mapRecord.find(target-nums[i]) == mapRecord.end())
            {
                mapRecord[nums[i]] = i;
                continue;
            }
            retVec.push_back(i);
            retVec.push_back(mapRecord[target - nums[i]]);
            break;
        }

        return retVec;
    }
};