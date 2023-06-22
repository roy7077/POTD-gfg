class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        
        int five=0;
        int ten=0;
        int tw=0;
        
        for(auto it:bills)
        {
            if(it==5)
            {
                five++;
                continue;
            }
            
            if(it==10)
            {
                if(five>=1)
                {
                    five--;
                    ten++;
                }
                else
                return false;
            }
            else if(it==20)
            {
                if(ten>=1 and five>=1)
                {
                    ten--;
                    five--;
                    tw++;
                }
                else if(five>=3)
                {
                    five-=3;
                    tw++;
                }
                else
                return false;
            }
        }
        
        return true;
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)
