class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        for(int i=0;i<=32;i++)
        {
            if(n&(1<<i))
            return i+1;
        }
        
        return 0;
    }
};

