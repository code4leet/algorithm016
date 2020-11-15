class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int size = s.size();
        for(int i = 0; i<size;++i)
        {
            arr[s[i]-'a']++;
        }
        for(int i =0; i< size;++i)
        {
            if(arr[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};