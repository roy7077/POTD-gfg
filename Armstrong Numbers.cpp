// Time complexity - O(18) - constant
// Space complexity- O(1) - constant
class Solution {
    public:
    string armstrongNumber(int n){
        int temp=n;
        int sum=0;
        while(temp)
        {
            sum+=pow(temp%10,3);
            temp/=10;
        }
        
        if(sum==n)
        return "Yes";
        else
        return "No";
    }
};