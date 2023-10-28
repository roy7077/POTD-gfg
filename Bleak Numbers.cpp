/*------------- ALL  POSSIBLE  APPROACHES -----------------*/


/*----------APPROACH - 1 (TLE)----------*/
class Solution
{
    public:
	int is_bleak(int n)
	{
	    for(int i=1;i<=n;i++)
	    {
	        if(i+__builtin_popcount(i)==n)
	        return 0;
	    }
	    
	    return 1;
	}
};


/*-----------APPROACH - 2 (TLE)------------*/
class Solution
{
    public:
    int countSetBits(int num) 
    {
        bitset<32> bits(num);  // Assuming a 32-bit integer
        return bits.count();
    }
	int is_bleak(int n)
	{
	    for(int i=1;i<=n;i++)
	    {
	        if(i+countSetBits(i)==n)
	        return 0;
	    }
	    
	    return 1;
	}
};


/*-------------APPROACH -3 -----------------*/
class Solution
{
    public:
    int is_bleak(int n)
    {
        
        for (int i = n - 1; i >= n - ceil(log2(n)); i--)
        {
            if (i + __builtin_popcount(i) == n)
                return 0;
        }

        return 1;
    }
};

/*---------------APPROACH - 4 -------------------*/
class Solution
{
    public:
    int countSetBits(int x)
    {
        int count = 0;
        while (x) 
        {
            x &= (x - 1);
            count++;
        }
        return count;
    }
    int ceilLog(int x)
    {
        int count = 0;
        x--;
        while (x > 0) 
        {
            x = x >> 1;
            count++;
        }
        return count;
    }
    
   int is_bleak(int n)
   {
       for (int x = n-ceilLog(n); x < n; x++)
       {
           if (x + countSetBits(x) == n)
           return 0;
       }
       return 1;
   }
};