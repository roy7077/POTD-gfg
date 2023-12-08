// TWO  APPROACHES
/*------1. Prime Sieve (TLE)----------------*/
#define ll long long
class Solution
{
    public:
    bool flag=0;
    vector<int> prime;
    void prime_seive()
    {
        int n=1000001;
        prime.resize(1000001,1);
        prime[0]=0;
        prime[1]=0;
        prime[2]=1;
        
        for(int i=2;i*i<n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)
                prime[j]=0;
            }
        }
    }
    
    int minNumber(int arr[],int N)
    {
        if(!flag)
        {
            prime_seive();
            flag=1;
        }
        
        ll sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        for(int i=sum;i<1e5;i++)
        {
            if(prime[i])
            return (i-sum);
        }
        
        return 0;
    }
};

/*----------2. Prime Function ()---------------*/
#define ll long long
class Solution
{
    public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return 0;
        }
        return 1;
    }
    
    int minNumber(int arr[],int N)
    {
        ll sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        ll temp=sum;
        while(1)
        {
            if(isPrime(temp))
            return temp-sum;
            else
            temp++;
        }
        
        return 0;
    }
};