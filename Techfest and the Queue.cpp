/*-----TWO APPROACHES---------*/

//METHOD - 1
// Time complexity - O((b-a)*logN)
// Space complexity- O(1)
class Solution {
    public:
    int help(int a)
    {
        int cnt=0;
        for(int i=2;i*i<=a;i++)
        {
            while(a%i==0)
            {
                cnt++;
                a/=i;
            }
        }
        
        if(a>1)
        cnt++;
        
        return cnt;
    }
	int sumOfPowers(int a, int b){
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int cnt=help(i);
	        ans+=cnt;
	    }
	    
	    return ans;
	}
};

//METHOD - 2 (prime sieve) - TLE
class Solution {
    public:
    bool flag=0;
    vector<int> prime;
    void seive()
    {
        int n=1e6+1;
        prime.resize(n,1);
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                prime[i]=i;
                for(int j=i*i;j<=n;j+=i)
                {
                    if(prime[j]==1)
                    prime[j]=i;
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(prime[i]==1)
            prime[i]=i;
        }
        
    }
    
    int help(int a)
    {
        int cnt=0;
        while(a>1)
        {
            a/=prime[a];
            cnt++;
        }
        
        return cnt;
    }
    
	int sumOfPowers(int a, int b){
	    if(flag==0)
	    {
	        seive();
	        flag=1;
	    }
	    
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int cnt=help(i);
	        ans+=cnt;
	    }
	    
	    return ans;
	}
};