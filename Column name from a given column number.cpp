#define ll long long
class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n)
        {
            ll rem=(n-1)%26;
            ans=char(rem+65)+ans;
            n=(n-1)/26;
        }
        return ans;
    }
};