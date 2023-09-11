/* Try to think of number, e.g.19, as a position.
   So with every pass the position changes.

    From 19 →10 → 7…..
    
    and it is calculated by,
    subtracting, deleted positions before 19 with every pass.
    
     
    i.e. Pass 1, where 2nd item is deleted.
    19 - (19/2) = 10 (new position)
*/

class Solution{
    public:
    bool isLucky(int n) {
        
        int cnt=2;
        while(1)
        {
            if(cnt>n)
            return true;
            
            if(n%cnt==0)
            return false;
            
            n-=(n/cnt);
            cnt++;
        }
        
        return true;
    }
};