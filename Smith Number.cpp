//TWO  APPROACHES


/*-------1. Prime Seive (TLE)----------*/
class Solution {
    public:
  
    bool flag=1;
    vector<int> prime;
    
    // function for prime seive
    void prime_seive()
    {
        int n=1000001;
        prime.resize(n,1);
        prime[0]=0;
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    if(prime[j]==1)
                    prime[j]=i;
                }
            }
        }
        
        for(int i=2;i<n;i++)
        {
            if(prime[i]==1)
            prime[i]=i;
        }
    }
    
    //function to calculate sum of primes
    int sumOfPrime(int n)
    {
        int primeSum=0;
        int temp=n;
        while(n)
        {
            if(n==temp and prime[n]==n)
            break;
            
            if(n==1)
            break;
            
            int fct=prime[n];
            while(fct)
            {
                primeSum+=fct%10;
                fct/=10;
            }
            
            n/=prime[n];
        }
        
        return primeSum;
    }
    
    
    //function to calculate sum of digits
    int sumOfDigit(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    
    int smithNum(int n) {
        
        if(flag)
        {
            prime_seive();
            flag=0;
        }
        
        int digitSum=sumOfDigit(n);
        int primeSum=sumOfPrime(n);
        
        if(digitSum==primeSum)
        return 1;
        else
        return 0;
    }
};


/*-----------2. Optimized------------*/
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
  
    //function to calculate sum of digits of prime
    int sumOfPrime(int n)
    {
        int sum=0;
        int temp=n;
        for(int i=2;i*i<=n;i++)
        {
            if(!(n%i))
            {   
                while(n%i==0)
                {
                    n/=i;
                    
                    int fct=i;
                    while(fct)
                    {
                        sum+=fct%10;
                        fct/=10;
                    }
                }
            }
        }
        
        if(n==temp)
        return sum;
        
        if(n>1)
        {
            while(n)
            {
                sum+=n%10;
                n/=10;
            }
        }
        
        return sum;
    }
    
    //function to calculate sum of digits
    int sumOfDigit(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    int smithNum(int n) {
        
        int sum1=sumOfPrime(n);
        int sum2=sumOfDigit(n);
    
    
        if(sum1==sum2)
        return 1;
        else
        return 0;
    }
};