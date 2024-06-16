// Simple Loop
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(!(n%i))
            return 0;
        }
        return 1;
    }
    vector<int> getPrimes(int n) {
        for(int i=2;i<=(n/2);i++)
        {
            if(isPrime(i) and isPrime(n-i))
            return {i,n-i};
        }
        return {-1,-1};
    }
};


// Prime Sieve
// Time complexity - O(Nlog(logN))
// Space complexity- o(N)
class Solution {
    public:
    static bool flag;
    static vector<int> prime;

    static void sieve(vector<int>& prime) 
    {
        int n=1000001;
        prime.resize(n,1);
        prime[0]=prime[1]=0;

        for(int i=2;i*i<=n;i++) 
        {
            if(prime[i]) 
            {
                for(int j=i *i;j<=n;j+=i)
                prime[j]=0;
            }
        }
        flag=1;
    }

    vector<int> getPrimes(int n) 
    {
        if(!flag)
        sieve(prime);

        int a=1e9;
        int b=1e9;

        for (int i=2;i<=n;i++) 
        {
            int n1=i;
            int n2=n-i;

            if(n1>n2) 
            {
                int temp=n1;
                n1=n2;
                n2=temp;
            }

            bool ans1=prime[n1];
            if(!ans1)
            continue;

            bool ans2=prime[n2];
            if(!ans2)
            continue;

            if(n1 < a) 
            {
                a=n1;
                b=n2;
            }
        }

        if(a>=1e9)
        return {-1,-1};
        else
        return {a,b};
    }
};

// Define and initialize the static members
bool Solution::flag = false;
vector<int> Solution::prime;