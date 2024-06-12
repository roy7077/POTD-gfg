// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool isFour(int n)
    {
        while(n)
        {
            if(n%10==4)
            return 1;
            
            n/=10;
        }
        return 0;
    }
    int countNumberswith4(int n) {
        int cnt=0;
        for(int i=0;i<=n;i++)
        {
            if(isFour(i))
            cnt++;
        }
        return cnt;
    }
};