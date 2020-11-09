class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> ans(num+1,0);
        for(int i = 0; i<num+1; ++i)
        {
            ans[i] = ans[i>>1] + (i & 1);
        }
        return ans;
    }
};


// 动态规划 + 最低有效位
// 状态转移方程:f(num)=f(num>>1) + (num&1)
// num&1 取得最低为是否为1