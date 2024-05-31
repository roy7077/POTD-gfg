// Time complexity - O(N)
// Space complexity- O(8) - constant
class Solution {
    public:
    int swapNibbles(int n) {
        vector<int> bits;
        int cnt=0;
        for(int i=0;i<8;i++)
        {
            cnt++;
            if(n&(1<<i))
            {
                if(cnt<=4)
                bits.insert(bits.begin(),1);
                else
                bits.push_back(1);
            }
            else
            {
                if(cnt<=4)
                bits.insert(bits.begin(),0);
                else
                bits.push_back(0);
            }
        }
        
        reverse(bits.begin()+4,bits.end());
        
        int decimal=0;
        int power=1;
        for(int i=bits.size()-1;i>=0;i--)
        {
            if(bits[i])
            decimal+=power;
            
            power*=2;
        }
        
        return decimal;
    }
};