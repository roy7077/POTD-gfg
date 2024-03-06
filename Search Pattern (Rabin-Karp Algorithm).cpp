
/* Rabin-Karp Algorithm 
   Time complexity - O(N)
   Space complexity- O(1)
*/
#define ll long long
int mod=1e9+7;
class Solution
{
    public:
    vector<int> search(string p, string s)
    {
        vector<int> ans;
        ll patHash=0;
        ll pr=1;
        for(int i=0;i<p.length();i++)
        {
            patHash=(patHash+((p[i]-'a'+1)*pr)%mod)%mod;
            pr=(pr*31)%mod;
        }
        
        ll txtHash=0;
        pr=1;
        for(int i=0;i<p.length();i++)
        {
            txtHash=(txtHash+((s[i]-'a'+1)*pr)%mod)%mod;
            pr=(pr*31)%mod;
        }
        
        int i=0;
        int j=p.length()-1;
        ll pr1=1;
        ll pr2=pr;
        
        if(patHash==txtHash)
        ans.push_back(1);
        
        while(j+1<s.length())
        {
            j++;
            txtHash=(txtHash+((s[j]-'a'+1)*pr2)%mod)%mod;
            txtHash=(txtHash-((s[i]-'a'+1)*pr1)%mod + mod )%mod;
            patHash=(patHash*31)%mod;
            i++;
            
            if(patHash==txtHash)
            ans.push_back(i+1);
            
            
            pr1=(pr1*31)%mod;
            pr2=(pr2*31)%mod;
        }
        return ans;
    }
};
