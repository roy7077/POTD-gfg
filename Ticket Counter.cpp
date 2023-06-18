class Solution {
  public:
    int distributeTicket(int N, int k) {
        
        int i=1;
        int j=N;
        bool flag=1;
        int cnt=k;
        
        while(i<=j)
        {
            //base case
            if(i==j)
            return i;
            
            if(flag)
            {
                i++;
                cnt--;
            }
            else
            {
                j--;
                cnt--;
            }
            
            if(cnt==0)
            {
                cnt=k;
                flag=(!flag);
            }
        }
    }
};

// time complexity - O(N)
// space complexity- O(1)