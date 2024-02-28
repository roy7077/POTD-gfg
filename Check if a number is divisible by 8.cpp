/* Divisibility Rule of 8
   If the last 3 digit of a number is divisible by 8 
   then the whole number is divisible by 8.

   Time complexity - O(1)
   Space complexity- O(1)
*/
class Solution{
    public:
    int DivisibleByEight(string s){
        int num=0;
        int ten=1;
        for(int i=s.length()-1;i>=0 and i>=(s.length()-3);i--)
        {
            num+=((int(s[i]))*ten);
            ten*=10;
        }
        if(num%8)
        return -1;
        else
        return 1;
    }
};