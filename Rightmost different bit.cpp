/*---------------BIT  MANIPULATION----------------*/
// Time complexity - O(32)
// Space complexity- O(1)
class Solution
{
    public:
    int posOfRightMostDiffBit(int m, int n)
    {
        int i=0;
        while(i<=32)
        {
            int a=(1<<i)&m;
            int b=(1<<i)&n;
            if(a!=b)
            return (i+1);
            
            i++;
        }
        
        return -1;
    }
};

/*---------------------BINARY-------------*/
// Time complexity - O(32)
// Space complexity- O(1)
class Solution
{
    public:
    int posOfRightMostDiffBit(int m, int n) {
    int pos = 1;
    while(m or n) 
    {
        if(m%2 != n%2)
        return pos;
        
        m/=2;
        n/=2;
        pos++;
    }
    return -1;
  }
};