class Solution {
  public:
    int setBits(int N) {
       
        int cnt =0;
        
        while(N)
        {
            if(N&1)
            cnt++;
            
            N=N>>1;
        }
        
        return cnt;
    }
};