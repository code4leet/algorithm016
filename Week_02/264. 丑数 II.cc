class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int arr[n];
        arr[0] = 1;
        int a=0,b=0,c=0; // a代表丑数*2的下标，b代表丑数*3的下标，c代表丑数*5的下标
        for(int i=1; i<n; ++i)
        {
            int nNext = min(min(arr[a]*2,arr[b]*3),arr[c]*5); // 查找到最小数字填入arr
            if(nNext == arr[a]*2) ++a; // 对应下标+1
            if(nNext == arr[b]*3) ++b;
            if(nNext == arr[c]*5) ++c;
            arr[i] = nNext;
        }
        return arr[n-1];
    }
};