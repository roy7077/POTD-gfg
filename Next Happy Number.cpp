class Solution{
public:

    bool ishappy(int n)
    {
        //base case
        if(n==2 or n==3 or n==4 or n==5 or n==6 or n==8 or n==9)
        return false;
        
        if(n==1 or n==7)
        return true;
        
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        
        if(ishappy(sum))
        return true;
        else
        return false;
    }
    int nextHappy(int N){
        // code here
        
        N++;
        while(N<=1e9)
        {
            if(ishappy(N))
            return N;
            
            N++;
        }
        
        return -1;
    }
};