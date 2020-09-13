class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int nFlag = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                nums[nFlag++] = nums[i];
            }
        }
        while(nFlag<nums.size())
        {
            nums[nFlag++] = 0;
        }
        return;
    }
};