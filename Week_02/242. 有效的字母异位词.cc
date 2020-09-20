class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        int arr[26]{};
        for(int i=0;i<s.size();++i)
        {
            ++arr[s[i]-'a']; // s字符+
            --arr[t[i]-'a']; // t字符-
        }
        for(int i=0; i<26; ++i)
        {
            if(arr[i]!=0) return false;
        }
        return true;
    }
};