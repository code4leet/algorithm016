class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int size = s.size();
        vector<vector<int>> dp(size,vector<int>(size));
        for(int len = 0; len<size; ++len)
        {
            for(int i = 0;i+len<size; ++i)
            {
                int j = i+len;
                if(len == 0) 
                {
                    dp[i][j] = 1;
                }
                else if(len == 1) 
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                }
                if(dp[i][j] && len+1>ans.size())
                {
                    ans = s.substr(i,len+1);
                }
            }
        }
        return ans;
    }
};