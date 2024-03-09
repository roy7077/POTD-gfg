// Time complexity - O(N*r)
// Space complexity- O(N)
class Solution{
    public:
    char nthCharacter(string s, int r, int ind) {
        int n=s.length();
        while(r--)
        {
            string temp="";
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0')
                temp+="01";
                else
                temp+="10";
            }
            s=temp.substr(0,n);
        }
        return s[ind];
    }
};