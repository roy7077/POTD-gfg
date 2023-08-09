class Solution{
public: 
    long long int largestPrimeFactor(int N){
        
        int ans=0;
        
        for(int i=2;i*i<=N;i++)
        {
            if(N==0)
            break;
            
            while(N%i==0)
            {
                ans=max(ans,i);
                N/=i;
            }
        }
        
        if(N)
        ans=max(ans,N);
        
        return ans;
    }
};
