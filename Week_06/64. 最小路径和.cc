class Solution {
public:
	// 点的最小数值=min(上侧,左侧)+当前数值
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(); // 行
        int n = grid[0].size(); // 列
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> dp(grid); // 顺便初始化[0][0]
        
        for(int j=1; j<n; ++j)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j]; // 初始化第一行
        }

        for(int i=1; i<m; ++i)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0]; // 初始化第一列
        }

        for(int i=1; i<m; ++i) // 初始化其他所有
        {
            for(int j=1;j<n;++j)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};