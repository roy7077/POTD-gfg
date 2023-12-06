// Time complexity - O(18*N)
// Space complexity- O(1)
class Solution {
    public:
    void countOne(int n,int& cnt,int& x)
    {
        while(n)
        {
            if(n%10==x)
            cnt++;
            
            n/=10;
        }
    }
    
    int countX(int L, int R, int X) {
        int cnt=0;
        for(int i=L+1;i<R;i++)
        countOne(i,cnt,X);
        
        return cnt;
    }
};
