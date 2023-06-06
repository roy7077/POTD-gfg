// User function Template for C++
class Solution {
  public:
  
    vector<int> prime;
    void prime_seive()
    {
        prime.resize(100006,0);
        int n=100005;
        prime[0]=0;
        prime[1]=1;
        
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==0)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(prime[j]==0)
                    prime[j]=i;
                }
            }
        }
        
    }
    vector<int> leastPrimeFactor(int n) {
        
        prime_seive();
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            if(i==0)
            ans.push_back(0);
            else if(prime[i]!=0)
            ans.push_back(prime[i]);
            else
            ans.push_back(i);
        }
        
        return ans;
    }
};