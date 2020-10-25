class Solution {
public:
    int countSubstrings(string s) 
    {
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;++i) // 中心拓展：遍历过程中认为每一个字符都是中心字符 字符与后一个字符是中心字符组 
        {
            for(int j=0;j<=1;++j) // 以自身一点为中心和两点为中心
            {
                int l = i; // 左边界
                int r = i+j; // 右边界
                while(l>=0 && r<n && s[l--] == s[r++]) ans++;
            }
        }
        return ans;
    }
};