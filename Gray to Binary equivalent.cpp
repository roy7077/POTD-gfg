
/* 
  Method - 1
  Time complexity - O(logN)
  Space complexity- O(32)  - constant
*/
class Solution{
    public:
    void decimalToBinary(vector<int>& binary,int n)
    {
        while(n)
        {
            if((n%2))
            binary.push_back(1);
            else
            binary.push_back(0);
            
            n/=2;
        }
        
        while(binary.size()<32)
        binary.push_back(0);
        
        reverse(binary.begin(),binary.end());
    }
    int help(vector<int>& binary)
    {
        vector<int> grayCode(32,0);
        
        int j=0;
        while(binary[j]==0)
        j++;
        
        grayCode[j]=binary[j];
        for(int i=j+1;i<32;i++)
        grayCode[i]=grayCode[i-1]^binary[i];
        
        int grayCodeNum=0;
        for(int i=31;i>=0;i--)
        {
            if(grayCode[i])
            grayCodeNum+=pow(2,31-i);
        }
        return grayCodeNum;
    }
    int grayToBinary(int n)
    {
        vector<int> binary;
        decimalToBinary(binary,n);
        return help(binary);
    }
};

/*
   Method - 2
   Bit Manipulation
   Time complexity - O(32) - constant
   Space complexity- O(32) - constant
*/
class Solution{
    public:
    int help(int n)
    {   
        vector<int> grayCode(32,0);
        
        int j=0;
        while(j<=31 and (n&(1<<(31-j)))==0)
        j++;
        
        grayCode[j]=bool(n&(1<<(31-j)));
        for(int i=j+1;i<32;i++)
        {
            int bin=bool(n&(1<<(31-i)));
            int gray=grayCode[i-1];
            grayCode[i]=bin^gray;
        }
        
        int grayCodeDecimal=0;
        for(int i=31;i>=0;i--)
        {
            if(grayCode[i])
            grayCodeDecimal|=(1<<31-i);
        }
        
        return grayCodeDecimal;
    }
    int grayToBinary(int n)
    {
        return help(n);
    }
};

/* 
  Method - 3
  Time complexity - O(32)
  Space complexity- O(1)
*/
class Solution{
    public:
    int grayToBinary(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans^=n;
            n>>=1;
        }
        return ans;
    }
};