class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int nAns = 0;
        while(n != 0)
        {
            ++nAns;
            n = n&(n-1);
        }
        return nAns;
    }
};