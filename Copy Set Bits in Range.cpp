class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        
        l--;
        while(l<r)
        {
            if(y&(1<<l))
            x=x|1<<l;
            
            l++;
        }
        
        return x;
    }
};