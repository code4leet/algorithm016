class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        std::reverse(digits.begin(),digits.end());
        int nFlag = 1; // +1标志
        for(int& num: digits)
        {
            if(num == 9)
            {
                num = 0;
                continue;
            }
            ++num;
            nFlag = 0;
            break;
        }
        if(nFlag)
        {
            digits.push_back(1);
            nFlag = 0;
        }
        std::reverse(digits.begin(),digits.end());
        return digits;
    }
};