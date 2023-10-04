// Time complexity - O(N)
// Space complexity- O(1)

/* APPROACH
   ________
   
   if current is less than next then substract
   if current is greather than next then add
   
   example :-
   IV - 1 < 5 => (-1)+5 = 4
   VI - 5 > 1 => (5-1)  = 4
*/

class Solution {
    public:
    int romanToDecimal(string &str) {
        
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            // if its last index
            if(i==str.length()-1)
            {
                num+=(mp[str[i]]);
                continue;
            }
            
            if(mp[str[i]]<mp[str[i+1]])
            num+=(-mp[str[i]]);
            else
            num+=mp[str[i]];
        }
        
        return num;
    }
};